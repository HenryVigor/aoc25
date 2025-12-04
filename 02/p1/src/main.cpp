#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "input/getFirstFile.h"

int main() {
    std::ifstream file = getFirstFile();
    if (!file) return 1;

    std::string range;
    long idSum = 0;
    while (std::getline(file, range, ',')) {
        int dashPos = range.find('-');
        if (dashPos == std::string::npos) continue;

        long i = std::stol(range.substr(0, dashPos));
        long end = std::stol(range.substr(dashPos + 1));
        for (; i <= end; i++) {
            std::string value = std::to_string(i);
            int len = value.length();
            if (len % 2) continue;

            int firstHalf = std::stoi(value.substr(0, len / 2));
            int secondHalf = std::stoi(value.substr(len / 2));

            if (firstHalf == secondHalf) idSum += i;
        }
    }

    std::cout << "Solution: " << idSum << '\n';
}
