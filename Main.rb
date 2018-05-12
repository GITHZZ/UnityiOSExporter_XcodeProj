PROJECT_ROOT_PATH = File.dirname(__FILE__)
SDK_FOLDER_NAME = "4399" #sdk对应的文件夹名字
PROJECT_RESOURCE_PATH = "#{PROJECT_ROOT_PATH}/mods/SDK/#{SDK_FOLDER_NAME}" 

#为了兼容开发机不能上网情况 只能本地化 不折腾了
$LOAD_PATH << File.join(PROJECT_ROOT_PATH, "/lib")

require "xcodeproj"
require_relative "XcodeProjectUpdater"

$project_folder_path = "/Users/hezunzu/Develop/unity/UnityXcodeApiExport/UnityXcodeApiExport"
$project_path = "#{$project_folder_path}/Unity-iPhone.xcodeproj"

$project = Xcodeproj::Project.open($project_path)

export_main = XcodeProjectUpdater.new()
export_main.start()

$project.save