require_relative "helper"

class PbxprojLoader
    attr_reader :project, :target, :sdk_config, :system_config
    attr_accessor :header_search_paths, :library_search_paths, :framework_search_paths

    def initialize()
        @sdk_config = SDK_CONFIG
        @system_config = SYSTEM_CONFIG
        
        backup_or_revert_pbxproj()
        copy_group_resource_to_project()

        @project = Xcodeproj::Project.open(@sdk_config["xcodeproj_path"])
        @target  = @project.targets.first

        @header_search_paths    = get_build_setting(@target, "HEADER_SEARCH_PATHS")
        @library_search_paths   = get_build_setting(@target, "LIBRARY_SEARCH_PATHS")
        @framework_search_paths = get_build_setting(@target, "FRAMEWORK_SEARCH_PATHS")
    end 

    def is_embed_frameworks?(path)
        basename = Pathname.new(path).basename.to_s
        if PbxprojHelper.win32?
            embed_framework_list = SDK_CONFIG["embed_framework_list"]
            embed_framework_list.each do |fremework_name|
                if framework_name == basename
                    return true
                end
            end
            return false
        else
            return PbxprojHelper.framework_is_embed(path)
        end  
    end 
    
    def get_embed_frameworks()
        # 先从已有的获取
        copy_files_build_phases = @target.copy_files_build_phases
        copy_files_build_phases.each do |build_phases|
            name = build_phases.name
            if name.to_s == "Embed Frameworks"
                return build_phases
            end 
        end

        # 如果没有，则自己创建
        embed_build_phases = @target.new_copy_files_build_phase("Embed Frameworks")
		embed_build_phases.symbol_dst_subfolder_spec = :frameworks  #暂时只支持framework类型 后续扩展
        return embed_build_phases
    end 

    def get_build_setting(target, key, build_configuration_name = "All")
        target.build_configurations.each do |config|
            if build_configuration_name == "All" || build_configuration_name == config.to_s 
                build_settings = config.build_settings
                if build_settings.has_key?(key)
                    return build_settings[key]
                else
                    return []
                end
            end 
        end 
        return []
    end 

    # 在修改xcode之前，先将原文件的pbxproj备份一次，然后下次修改时候先从备份文件还原，再进行下一次操作
    # 主要是为了避免频繁操作导致pbxproj文件乱问题
    def backup_or_revert_pbxproj()
        xcodeproj_path = @sdk_config["xcodeproj_path"]
        pbxproj_file_path = xcodeproj_path + "/project.pbxproj"
        backup_pbxproj_file_path = xcodeproj_path + "/.project.pbxproj_backup"

        if (File::exist?(backup_pbxproj_file_path))
            FileUtils.rm_r pbxproj_file_path
            FileUtils.cp_r backup_pbxproj_file_path, pbxproj_file_path
        else
            FileUtils.cp_r pbxproj_file_path, backup_pbxproj_file_path
        end 
    end
    
    # 不直接引用资源目录下的资源，先复制到工程下 再进行引用
    def copy_group_resource_to_project()
        xcodeproj_path = @sdk_config["xcodeproj_path"]
        sdk_res_path = @sdk_config["sdk_res_path"]

        project_folder_path = File.dirname(xcodeproj_path)

        group_relative_path = Pathname.new(sdk_res_path).basename.to_s
        group_full_path = project_folder_path + "/" + Pathname.new(sdk_res_path).basename.to_s
        
        @sdk_config["group_relative_path"] = group_relative_path
        @sdk_config["group_full_path"] = group_full_path

        if !sdk_res_path.empty?
            FileUtils.cp_r sdk_res_path, project_folder_path
        else # 如果没有传sdk路径 那么直接使用工程路径
            sdk_res_path = project_folder_path
        end
    end 

    def description()
        content = "xcodeproj={
            projectInfo = #{@project},
            header_search_paths    = {#{@header_search_paths}},
            library_search_paths   = {#{@library_search_paths}},
            framework_search_paths = {#{@framework_search_paths}}
        }"
        puts content
    end 

    def free()
        @project.save
    end 
end 