module PbxprojHelper
    def framework_is_embed(path)
        shell_string = "file\t" + path
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