require_relative "modify"

class Driver
    def initialize()
        @support_method_config = Hash.new
        class_list = [
            PbxprojModify.new()
        ]
        
        # 按顺序存储方法
        method_index = 1
        class_list.each do |cls|
            method_list = cls.get_shell_support_function()
            method_list.each do |method_name|
                m = cls.method(method_name)
                @support_method_config[method_index.to_s] = m
                method_index += 1
            end
        end 
    end 

    def call(index)
        if !@support_method_config.has_key?(index)
            puts "【错误提示】不支持的方法序列号:" + index
            return
        end 
        @support_method_config[index].call
    end 

    def description()
        content = "\t支持的方法名字列表（序列:方法名):\n"
        @support_method_config.each do |index, method|
            content += "\t\t" + index + ":" + method.name.to_s + "\n"
        end 
        return content
    end
end