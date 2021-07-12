class CapabilityType
    # 权限配置内容
    # id:苹果权限唯一id字符串 如:"com.apple.ApplicationGroups.iOS"
    # 详情请见:https://developer.apple.com/documentation/bundleresources/entitlements
    # request_entitlements:是否写入到plist文件中
    # framework:需要添加到工程的framework（某些Capability需要绑定framework）
    # optional_framework:判断framework是否为optional类型
    attr_reader :id, :request_entitlements, :framework, :optional_framework

    def initialize(id, request_entitlements = false, framework = "", optional_framework = false)
        @id = id
        @request_entitlements = request_entitlements
        @framework = framework
        @optional_framework = optional_framework
    end
end

class CapabilityManager
    def get_shell_support_function()
        return []
    end 
    
    def init()
        @apple_sign = CapabilityType.new("com.apple.developer.applesignin", true)
        @push_notifications = CapabilityType.new("aps-environment", true)
        @inapp_purchase = CapabilityType.new("com.apple.InAppPurchase", false, "StoreKit")
    end 

    # 初始化需要传入两个参数
    # productName：app二进制名字
    # to_folder：需要将entitlements放到哪个文件夹中 这个一般传入sdk文件夹即可
    def set_info(product_name, to_folder = "")
        @entitlements_file_name = product_name.to_s + ".entitlements"
        @entitlements_content = Hash.new
        @entitlements_save_folder = to_folder

        @support_method_config = Hash.new

        # 注册可以支持的方法名字
        regist_support_method() 
    end 

    def regist_support_method()
        method_name_list = [
            "add_apple_sign",
            "add_push_notifications",
            "add_inapp_purchase"
        ]
        method_name_list.each do |method_name|
            m = self.method(method_name)
            @support_method_config[method_name] = m
        end
    end 

    def call(method_name, args)
        if !@support_method_config.has_key?(method_name)
            puts "【错误提示】不支持的方法名字:" + method_name
            return
        end
        @support_method_config[method_name].call
    end 

    # 新增苹果登陆
    def add_apple_sign(*args)
        id = @apple_sign.id
        @entitlements_content[id] = ["Default"]
        return @apple_sign
    end

    # 新增通知标签
    def add_push_notifications(*args)
        id = @push_notifications.id
        @entitlements_content[id] = "development"
        return @push_notifications
    end 
   
    # 新增内购
    def add_inapp_purchase(*args)
        id = @inapp_purchase.id
        fremework = @inapp_purchase.framework
        return @inapp_purchase
    end 

    def save()
        to_path = @entitlements_save_folder + "/" + @entitlements_file_name
        @entitlements_content.save_plist(to_path)
        return @entitlements_file_name
    end

    def description()
        content = "CapabilityManager={"
        @support_method_config.each do |method_name, method|
            content += method_name.to_s + "\n"
        end
        content += "}"
    end
end