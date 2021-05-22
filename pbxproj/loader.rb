require_relative "helper"

class PbxprojLoader
    attr_reader :xcodeproj_path, project, :target
    attr_accessor :header_search_paths, :library_search_paths, :framework_search_paths

    def initalize(xcodeproj_path)
        @xcodeproj_path = xcodeproj_path
    end 

    def get_build_setting(target, key, build_configuration_name = "All")
        target.build_configurations.each do |config|
            if build_configuration_name == "All" || build_configuration_name == config.to_s then
                build_settings = config.build_settings
                return build_settings[key]
            end 
        end 
    end 

    # 在修改xcode之前，先将原文件的pbxproj备份一次，然后下次修改时候先从备份文件还原，再进行下一次操作
    # 主要是为了避免频繁操作导致pbxproj文件乱问题
    def backup_or_revert_pbxproj()
        pbxproj_file_path = xcodeproj_path + "/project.pbxproj"
        backup_pbxproj_file_path = xcodeproj_path

        if (File::exist?(backup_pbxproj_file_path))
            FileUtil.rm_r pbxproj_file_path
            FileUtil.cp_r backup_pbxproj_file_path, pbxproj_file_path
        else
            FileUtil.cp_r pbxproj_file_path, backup_pbxproj_file_path
        end 
    end
    
    def description()
        content = "xcodeproj={
            projectInfo = #{@project},
            header_search_paths = {#{@header_search_paths}},
            library_search_paths = {#{@library_search_paths}},
            framework_search_paths = {#{@framework_search_paths}}
        }"
        puts content
    end 

    def free()
        @xcodeproj_path = nil
        @project.save
    end 
end 