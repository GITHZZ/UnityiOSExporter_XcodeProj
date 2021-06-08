require "pathname" 

PROJECT_ROOT_FULL_PATH = Pathname.new(File.dirname(__FILE__)).realpath.to_s
PROJECT_ROOT_PATH = File.dirname(__FILE__)

# 配置搜索路径
$LOAD_PATH << File.join(PROJECT_ROOT_PATH, "/lib")

require "xcodeproj"
require "fileutils"
require "pathname"
require "optparse"
require "json"

require_relative "pbxproj/driver"

# 获取从shell传过来的参数
OPTIONS = {}
option_parser = OptionParser.new do |opts|
    # 这里是这个命令行工具的帮助信息
    opts.banner = '*打包工具-使用帮助'
    opts.on('-m', '--method index', "需要运行的方法序列号:\n") do |value|
        OPTIONS["method_index"] = value
    end
    opts.on('-c', '--config path', "配置序列号") do |value|
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

jsonContent = File.read("Config.json")
configTable = JSON.parse(jsonContent)
config = configTable[config_key] # 获取具体配置

GROUP_ROOT_NAME = config["group_root_name"]
GLOBAL_CONFIG = config

driver = Driver.new
desc = driver.description()

# 调用方法
driver.call(method_index)