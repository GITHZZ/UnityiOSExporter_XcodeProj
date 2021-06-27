PROJECT_ROOT_PATH = File.dirname(__FILE__)

# 配置搜索路径
$LOAD_PATH << File.join(PROJECT_ROOT_PATH, "/lib")

require "plist"
require_relative "pbxproj/capability"

capability_manager = CapabilityManager.new("productName")
capability_manager.add_apple_pay()
capability_manager.write_to_file()
