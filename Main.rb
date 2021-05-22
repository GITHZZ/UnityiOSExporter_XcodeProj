# 测试配置 
config = Hash.new 
config = { 
    "xcodeproj_path" => "tests/samplescli/Unity-iPhone-ydssssyd1ios.xcodeproj", 
    "sdk_res_path" => "tests/samples", 
    "group_root_name" => "SDK",
    "embed_framework_list" => ["FBSDKLoginKit.framework"], 
    "system" => { "mac_password" => 4399, "p12_password" => 4399 } 
}

PROJECT_ROOT_PATH = File.dirname(__FILE__)
GROUP_ROOT_NAME = config["group_root_name"]
GROUP_RELATIVE_PATH = config["sdk_res_path"]

GLOBAL_CONFIG = config

# 配置搜索路径
$LOAD_PATH << File.join(PROJECT_ROOT_PATH, "/lib")

require "xcodeproj"
require "fileutils"
require "pathname"

