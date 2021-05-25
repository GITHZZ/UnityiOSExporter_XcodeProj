require 'fileutils'

class CodeSigner
    def initialize(mac_password, p12_password)
        # 用户目录
        home_dir = ENV["HOME"]
        # 登陆钥匙串路径
        @login_key_chain_path = home_dir + "/Library/Keychains/login.keychain-db"
        # 签名文件存放路径
        @mobile_device_dir = home_dir + "/Library/MobileDevice/Provisioning Profiles"
        # 苹果电脑密码
        @mac_password = mac_password
        # 苹果p12文件密码
        @p12_password = p12_password
    end 

    def import_p12(file_path)
        if !File.exist?(file_path) 
            puts file_path + ":p12文件不存在，请确认路径是否正确。"
            return
        end 

        # 解锁登陆密码
        `security unlock-keychain -p #{@mac_password} #{@login_key_chain_path}`

        # 免密打包
        `security set-keychain-settings #{@login_key_chain_path}`

        # 导入p12文件
        `security import #{file_path} -k #{@login_key_chain_path} -P #{@p12_password} -A -T /usr/bin/codesign`
    end 

    def import_mobileprovision(file_path)
        if !File.exist?(file_path)
            puts file_path + ":mobileprovision 文件不存在，请确认路径是否正确。"
            return
        end 
        
        file_folder_path = File.dirname(file_path)
        
        output_file_name = "tmp.xml"
        output_file_full_path = file_folder_path + "/" + output_file_name

        # 如果存在文件就先删除掉
        if File.exist?(output_file_full_path)
            File.delete(output_file_full_path)
        end 

        # 将mobileprovision文件解析成xml格式
        `security cms -D -i #{file_path} > #{output_file_full_path}`

        xml_content = Plist.parse_xml(output_file_full_path)
        uuid = xml_content["UUID"]
        
        # 需要复制到Provisioning Profiles目录下并且使用uuid作为名字才会生效
        FileUtils.cp(file_path, @mobile_device_dir + "/" + uuid + ".mobileprovision")
    end
end 