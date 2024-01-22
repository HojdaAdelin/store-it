#include "Storing.h"
#include <filesystem>
#include <windows.h>
#include <string>
#include <iostream>

namespace fs = std::filesystem;

void Storing::AutoStore(std::string location) {

    std::string extensions[25] = {"txt", "pdf", "cpp", "docs", "docx", "pdf", "py", "java", "js", "c", "h", "cs", "class",
    "rb", "html", "css", "php", "jpg", "png", "ico", "svg", "mp3", "mp4", "avi", "wmv"};
    std::string folder_names[25] = {"TxtFolder", "PDFFolder", "CppFolder", "WordFolder", "WordFolder", "PPFolder", "PyFolder", "JavaFolder", "JavaScriptFolder", "CFolder", "HeaderFolder",
    "C#Folder", "ClassFolder", "RubyFolder", "HtmlFolder", "CssFolder", "PhpFolder", "PhotoFolder", "PhotoFolder", "PhotoFolder", "PhotoFolder", "AudioFolder", "VideoFolder",
    "VideoFolder", "VideoFolder"};

    for (const auto& entry : fs::directory_iterator(location)) {
        if (entry.is_regular_file()) {
            std::string fileExtension = entry.path().extension().string().substr(1); // Remove the dot
            bool found = false;

            for (int i = 0; i < 7; i++) {
                if (fileExtension == extensions[i]) {
                    std::string destinationFolder = location + "\\" + folder_names[i];
                    fs::create_directory(destinationFolder); 

                    fs::copy(entry.path(), destinationFolder + "\\" + entry.path().filename().string());

                    std::cout << "Moved " << fileExtension << " file to " << destinationFolder << std::endl;
                    fs::remove(entry.path());
                    found = true;
                    break; 
                }
            }

            if (!found) {
                std::string destinationFolder = location + "\\" + "OtherFolder";
                fs::create_directory(destinationFolder); 

                fs::copy(entry.path(), destinationFolder + "\\" + entry.path().filename().string());

                std::cout << "Moved " << fileExtension << " file to " << destinationFolder << std::endl;
                fs::remove(entry.path());
            }
        }
    }

}
