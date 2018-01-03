require "json"
require "fileutils"

class XcodeProjectUpdater
	def initialize()
		@target = $project.targets.first

		@group_root_path = 'SDK'
		@group_sub_path = @group_root_path

		@framework_search_paths_array = Array.new()

		@unity_class_group = new_group(File.join(@group_root_path), PROJECT_RESOURCE_PATH)

		@framework_group = $project.main_group.find_subpath("Frameworks")
	end

	def start()
		#移除所有旧的引用
		if !@unity_class_group.empty?
			remove_build_phase_files_recursively(@target, @unity_class_group)
			@unity_class_group.clear()
		end 

		#新增引用
		add_build_phase_files(@target, @unity_class_group, PROJECT_RESOURCE_PATH)
		#新增Framework查找路径
		set_framework_search_path()
	end 

	def remove_build_phase_files_recursively(target, group)
		group.groups.each do |sub_group|
			remove_build_phase_files_recursively(target, sub_group)
		end 

		group.files.each do |file|
			if file.real_path.to_s.end_with?(".m", ".mm", ".cpp") 
				target.source_build_phase.remove_file_reference(file)
			elsif file.real_path.to_s.end_with?(".framework") 
				target.frameworks_build_phases.remove_file_reference(file)
			elsif file.real_path.to_s.end_with?(".bundle") 
				target.resources_build_phase.remove_file_reference(file)
			end
		end 
	end 

	def add_build_phase_files(target, group, path)
		Dir.foreach(path) do |dir|
			newPath = "#{path}/#{dir}"

			#Classes为特殊文件夹-过滤
			if dir != '.' and dir != '..' and dir != '.DS_Store' 
				file_type = File::ftype(newPath)
				if dir == 'Classes'
					replace_unity_app_controller_file($project_folder_path, newPath)
				elsif file_type == 'directory' and !newPath.include?"." 
					@framework_search_paths_array.insert(@framework_search_paths_array.size - 1, newPath)

					@group_sub_path = "#{@group_sub_path}/#{dir}"
					new_group = new_group(File.join(@group_sub_path), newPath)
					
					add_build_phase_files(target, new_group, newPath)

					@group_sub_path = @group_root_path					
				elsif newPath.to_s.end_with?(".json")
					set_build_settings_form_config(newPath)
				else
					file_ref = group.new_reference(newPath)
					if newPath.to_s.end_with?(".m", ".mm", ".cpp") 
						target.source_build_phase.add_file_reference(file_ref)
					elsif newPath.to_s.end_with?(".framework") 
						target.frameworks_build_phases.add_file_reference(file_ref)
					elsif newPath.to_s.end_with?(".bundle") 
						target.resources_build_phase.add_file_reference(file_ref)
					end
				end
			end
		end 
	end 

	#新增一个xcode-group
	def new_group(path, relation_path)
		unity_class_group = $project.main_group.find_subpath(path, true)
		unity_class_group.set_source_tree('<group>')
		unity_class_group.set_path(relation_path)
		return unity_class_group
	end 

	#新增framework查找路径
	def set_framework_search_path()
		set_build_setting_form_current_target(@target, "FRAMEWORK_SEARCH_PATHS", @framework_search_paths_array)
	end 

	#需要查查 应该可以不这么写的
	def set_build_setting_form_current_target(target, key, value)
		target_build_settings_1 = target.build_settings("Debug")
		target_build_settings_2 = target.build_settings("Release")
		target_build_settings_3 = target.build_settings("ReleaseForProfiling")
		target_build_settings_4 = target.build_settings("ReleaseForRunning")

		target_build_settings_1[key] = value
		target_build_settings_2[key] = value
		target_build_settings_3[key] = value
		target_build_settings_4[key] = value
	end

	#覆盖UnityAppController中的文件UI
	def replace_unity_app_controller_file(xcode_project_path, mod_path)
		h_file_path = "#{mod_path}/UnityAppController.h"
		m_file_path = "#{mod_path}/UnityAppController.mm"

		if File::exist?(h_file_path)
			FileUtils.cp "#{mod_path}/UnityAppController.h", "#{xcode_project_path}/Classes"
		end 

		if File::exist?(m_file_path)
			FileUtils.cp "#{mod_path}/UnityAppController.mm", "#{xcode_project_path}/Classes"
		end
	end 

	#解析配置文件(新增系统相关库)
	def set_build_settings_form_config(config_path)
		config = File.read(config_path)
		setting_hash = JSON.parse(config)

		frameworks = setting_hash["frameworks"]
		libs = setting_hash["Libs"]
		linker_flags = setting_hash["linker_flags"]

		#新增系统framework
		@target.add_system_framework(frameworks)

		# frameworks.each do |item|	
		# 	puts item
		# 	file_refs = @target.add_system_framework()
		# 	@target.frameworks_build_phases.add_file_reference(file_ref)
		# end 
	end 

	def add_system_framework(names)

	end 
end
