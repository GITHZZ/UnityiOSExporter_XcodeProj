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
    # 初始化需要传入两个参数
    # productName：app二进制名字
    # to_folder：需要将entitlements放到哪个文件夹中 这个一般传入sdk文件夹即可
    def initialize(productName, to_folder = "")
        @entitlements_file_name = productName + ".entitlements"
        @entitlements_content = Hash.new
        @entitlements_save_folder = to_folder

        @apple_pay = CapabilityType.new("com.apple.developer.applesignin", true)
    end

    # 新增苹果支付权限
    def add_apple_pay()
        id = @apple_pay.id
        request_entitlements = @apple_pay.request_entitlements
        if request_entitlements 
            @entitlements_content[id] = ["Default"]
        end
    end

    def write_to_file()
        to_path = @entitlements_save_folder + "/" + @entitlements_file_name
        puts to_path

        @entitlements_content.save_plist(@entitlements_file_name)
    end
end