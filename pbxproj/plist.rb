class PbxprojPlist
    def initialize(file_path)
        if !File.exist?(file_path)
            puts "文件不存在，请确认路径"
            return
        end

        # plist = Plist.parse_xml(file_path)
        # puts plist
    end
end