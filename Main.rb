PROJECT_ROOT_PATH = File.dirname(__FILE__)
PROJECT_RESOURCE_PATH = "#{PROJECT_ROOT_PATH}/mods/SDK" 

#为了兼容开发机不能上网情况 只能本地化 不折腾了
$LOAD_PATH << File.join(PROJECT_ROOT_PATH, "/lib")

require "xcodeproj"
require_relative "XcodeProjectUpdater"

$project_folder_path = "/Users/a4399/Documents/Projects/XcodeExportTest/XcodeProj"
$project_path = "#{$project_folder_path}/Unity-iPhone.xcodeproj"

$project = Xcodeproj::Project.open($project_path)

export_main = XcodeProjectUpdater.new()
export_main.start()

$project.save
