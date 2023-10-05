#include "Storing.h"
#include <filesystem>
#include <windows.h>
#include <string>
#include <iostream>

namespace fs = std::filesystem;

void Storing::AutoStore(std::string location) {

    std::string extensions[7] = {"txt", "pdf", "cpp", "docs", "pdf", "py", "java"};
    std::string folder_names[7] = {"TxtFolder", "PDFFolder", "CppFolder", "WordFolder", "PPFolder", "PyFolder", "JavaFolder"};

    for (const auto& entry : fs::directory_iterator(location)) {
        if (entry.is_regular_file()) {
            std::string fileExtension = entry.path().extension().string().substr(1); // Remove the dot

            for (int i = 0; i < 7; i++) {
                if (fileExtension == extensions[i]) {
                    std::string destinationFolder = location + "\\" + folder_names[i];
                    fs::create_directory(destinationFolder); 

                    fs::copy(entry.path(), destinationFolder + "\\" + entry.path().filename().string());

                    std::cout << "Moved " << fileExtension << " file to " << destinationFolder << std::endl;
                    fs::remove(entry.path());
                    break; 
                }
            }
        }
    }

}