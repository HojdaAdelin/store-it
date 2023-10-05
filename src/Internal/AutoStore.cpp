#include "Storing.h"
#include <filesystem>
#include <windows.h>
#include <string>
#include <iostream>

namespace fs = std::filesystem;

void Storing::AutoStore(std::string location) {

    std::string extensions[5] = {"txt", "pdf", "cpp", "doc", "pdf"};
    std::string folder_names[5] = {"TxtFolder", "PDFFolder", "CodingFolder", "WordFolder", "PPFolder"};

    for (const auto& entry : fs::directory_iterator(location)) {
        if (entry.is_regular_file()) {
            std::string fileExtension = entry.path().extension().string().substr(1); // Remove the dot

            for (int i = 0; i < 5; i++) {
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