require "pathname" 
require "fileutils"
require "optparse"
require "json"

PROJECT_ROOT_FULL_PATH = Pathname.new(File.dirname(__FILE__)).realpath.to_s
PROJECT_ROOT_PATH = File.dirname(__FILE__)

# 配置搜索路径
$LOAD_PATH << File.join(PROJECT_ROOT_PATH, "/lib")
$LOAD_PATH << File.join(PROJECT_ROOT_PATH, "/pbxproj")

require "xcodeproj"
require "plist"
require "driver"

# 获取从shell传过来的参数
OPTIONS = {}
option_parser = OptionParser.new do |opts|
    # 这里是这个命令行工具的帮助信息
    opts.banner = "*打包工具-使用帮助"
    opts.on("-m", "--method index", "需要运行的方法序列号:\n") do |value|
        OPTIONS["method_index"] = value
    end
    opts.on("-c", "--config path", "配置序列号") do |value|
        OPTIONS["config_key"] = value
    end 
end
option_parser.parse!

method_index = OPTIONS["method_index"]
config_key = OPTIONS["config_key"]

if method_index.nil? || config_key.nil?
    puts "【错误提示】参数不全，请输入-h 查看具体需要传入的参数内容"
    return
end 

sdk_Json = File.read("config.json")
system_json = File.read("system.json")

sdk_map = JSON.parse(sdk_Json)
system_map = JSON.parse(system_json)

# 获取具体配置
SDK_CONFIG = sdk_map[config_key] 
SYSTEM_CONFIG = system_map 
GROUP_ROOT_NAME = SYSTEM_CONFIG["group_root_name"]

driver = Driver.new
driver.call(method_index)