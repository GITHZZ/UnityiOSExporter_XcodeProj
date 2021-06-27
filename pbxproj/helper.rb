module PbxprojHelper
    def framework_is_embed(path)
        exe_name = File.basename(path, ".*")
        exe_full_path = PROJECT_ROOT_FULL_PATH + "/" + SDK_CONFIG["sdk_res_path"] + "/" + path + "/" + exe_name

        shell_string = "file\t" + exe_full_path
        r = %x(#{shell_string})

        if r.include?("dynamically")
            return true
        end 
        return false
    end 

    def win32?
        require 'Win32API'
        return true
    rescue LoadError
        return false
    end 

    module_function :framework_is_embed
    module_function :win32?
end 