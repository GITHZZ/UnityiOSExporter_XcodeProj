require "singleton"

require_relative "loader"
require_relative "modify"
require_relative "capability"
require_relative "plist"

class Driver
    include Singleton

    def init()
        @class_list = [
            PbxprojModify.new(),
            PbxprojPlist.new(),
            CapabilityManager.new()
        ]
        
        @class_map = Hash.new
        @support_method_config = Hash.new

        # 按顺序存储方法
        method_index = 1
        @class_list.each do |cls|            
            name = cls.class.name
            @class_map[name] = cls
            
            method_name_list = cls.get_shell_support_function()
            method_name_list.each do |method_name|
                m = cls.method(method_name)
                @support_method_config[method_index.to_s] = m
                method_index += 1
            end
        end

        # 调用所有的初始化
        @class_map.each do |name, cls|
            cls.init()
        end
    end 

    def get_class(name)
        if !@class_map.has_key?(name)
            puts "不存在类名:" + name
            return
        end
        return @class_map[name]
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