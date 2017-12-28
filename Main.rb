PROJECT_ROOT_PATH = File.dirname(__FILE__)
PROJECT_RESOURCE_PATH = "#{PROJECT_ROOT_PATH}/mods/SDK" 

require "#{PROJECT_ROOT_PATH}/XcodeProjectUpdater"

$project_folder_path = "/Users/a4399/Documents/Projects/XcodeExportTest/XcodeProj"
$project_path = "#{$project_folder_path}/Unity-iPhone.xcodeproj"

$project = Xcodeproj::Project.open($project_path)

export_main = XcodeProjectUpdater.new()
export_main.start()

$project.save
