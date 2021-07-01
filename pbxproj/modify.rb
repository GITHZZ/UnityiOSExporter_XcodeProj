# 总体思路有所改变 不再是直接引用，而是将资源拷贝到工程中再进行引用
class PbxprojModify
    def get_shell_support_function()
        method_name_list = [
            "method_call_from_shell_1_0",
            "method_call_from_shell_2_0"
        ]
        return method_name_list
    end 

    def method_call_from_shell_1_0(*args)
        start()
        free()
    end 

    def method_call_from_shell_2_0(*args)
        generate_capability()
    end 

    def initialize()
        @loader = PbxprojLoader.new
        @project = @loader.project
        @target = @loader.target
        
        xcodeproj_path = @loader.xcodeproj_path
        product_name = @loader.product_name

        @capabilityManager = CapabilityManager.new(product_name, @loader.sdk_res_path)
        
        @group_name = GROUP_ROOT_NAME
        @group_child_name = @group_name

        dir_name = Pathname.new(@loader.group_full_path).basename.to_s
        
        #索引路径只获取最上层文件夹名字
        @group = create_group(File.join(@group_name), dir_name) 

        @framework_search_paths = @loader.framework_search_paths
        @header_search_paths    = @loader.header_search_paths
        @library_search_paths   = @loader.library_search_paths

        @embed_build_phases = @loader.get_embed_frameworks()
    end

    def start()
        add_build_phase_files(@target, @group, @loader.group_full_path)
        # 处理权限配置
        generate_capability()
        # 整理动态库 
        generate_embed_framework()
        # 整理系统库
        generate_system_framework()
        # 处理链接器参数
        generate_linker_flags()
        # 新增相关查找路径
		set_build_search_path()
    end 

    # project mark - create_group 生成模板
    # 
    # isa = PBXGroup
    # children = ();
    # name = name(传参值)
    # path = relative_path
    # sourceTree = <group>
    def create_group(name, relative_path)
        tmp_group = @project.main_group.find_subpath(name, true)
        tmp_group.set_source_tree('<group>')
        tmp_group.set_path(relative_path)
        return tmp_group
    end 

    # 该列表下不允许新增到引用工程
    IGNORE_FILE_INFO = {
        "."  => true,
        ".." => true,
        ".DS_Store" => true,
    }
    def add_build_phase_files(target, group, group_relative_path)
        if File.exists?(group_relative_path) == false
            puts group_relative_path + "\tpath is not exist"
            return
        end

        Dir.foreach(group_relative_path) do |dir|
            new_path = "#{group_relative_path}/#{dir}"
            file_type = File::ftype(new_path)

            if IGNORE_FILE_INFO.has_key?(dir) == false
                if file_type == "directory" and !new_path.to_s.end_with?(".bundle", ".framework")
                    @framework_search_paths.insert(@framework_search_paths.size - 1, new_path)
                    @header_search_paths.insert(@header_search_paths.size - 1, new_path)
                    @library_search_paths.insert(@library_search_paths.size - 1, new_path)

                    @group_child_name = "#{@group_child_name}/#{dir}"

                    dir_name = Pathname.new(dir).basename.to_s
                    child_group = create_group(File.join(@group_child_name), dir_name)
                    add_build_phase_files(target, child_group, new_path)

                    @group_child_name = File.dirname(@group_child_name) #回到上一个目录
                else
                    file_reference = group.new_reference(dir)
                    if new_path.to_s.end_with?(".m", ".mm", ".cpp")
                        target.source_build_phase.add_file_reference(file_reference)
                    elsif new_path.to_s.end_with?(".framework", ".a")
                        target.frameworks_build_phases.add_file_reference(file_reference)
                    elsif new_path.to_s.end_with?(".bundle", ".jpg", ".png")
                        target.resources_build_phase.add_file_reference(file_reference)
                    end
                end 
            end 
        end 
    end

    def generate_embed_framework()
        files_references = @target.frameworks_build_phases.files_references
        files_references.each do |ref|
            file_path = ref.path
            if !file_path.start_with?("System", "usr", "Libraries")
                if @loader.is_embed_frameworks?(file_path)
                    pbx_build_file = @embed_build_phases.add_file_reference(ref)
                    pbx_build_file.settings = {'ATTRIBUTES'=>['CodeSignOnCopy']}
                end 
            end
        end 
    end 

    def generate_system_framework()
        system_framework_list = @loader.system_framework
        @target.add_system_frameworks(system_framework_list)
    end 

    def generate_linker_flags()
        linker_flags = @loader.linker_flags
        linker_flags.insert(linker_flags.size - 1, "-weak_framework")
        linker_flags.insert(linker_flags.size - 1, "CoreMotion")
        linker_flags.insert(linker_flags.size - 1, "-weak-lSystem")
        set_build_setting(@target, "OTHER_LDFLAGS", linker_flags)
    end 

    def generate_capability()
        system_framework_list = []

        capability = @loader.capability
        capability.each do |method_name, args|
            capability_type = @capabilityManager.call(method_name, args)
            framework = capability_type.framework
            if !framework.empty?
                system_framework_list.push(framework)
            end 
        end

        @target.add_system_frameworks(system_framework_list)
        
        entitlements_file_name = @capabilityManager.save()
        entitlements_path_in_project = @loader.group_relative_path + "/" + entitlements_file_name
        set_build_setting(@target, "CODE_SIGN_ENTITLEMENTS", entitlements_path_in_project)
    end 

    def set_build_search_path()
        set_build_setting(@target, "FRAMEWORK_SEARCH_PATHS", @framework_search_paths)
		set_build_setting(@target, "HEADER_SEARCH_PATHS", @header_search_paths)
		set_build_setting(@target, "LIBRARY_SEARCH_PATHS", @library_search_paths)
		set_build_setting(@target, "LD_RUNPATH_SEARCH_PATHS", "$(inherited) @executable_path/Frameworks")
    end 

    def set_build_setting(target, key, value, build_configuration_name = "All")
        target.build_configurations.each do |config|
            if build_configuration_name == "All" || build_configuration_name == config.to_s
                build_settings = config.build_settings
                build_settings[key] = value
            end 
        end
    end

    def free()
        @loader.free()
    end 
end  