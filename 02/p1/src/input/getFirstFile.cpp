#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "getFirstFile.h"

std::ifstream getFirstFile() {
    std::ifstream file;
    for (const auto& entry : std::filesystem::directory_iterator("input")) {
        file = std::ifstream(entry.path());
        break;
    }

    return file;
}
