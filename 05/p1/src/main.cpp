#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "input/getFirstFile.h"

int main() {
    std::ifstream file = getFirstFile();
    if (!file) return 1;

    // Get ranges
    std::string line;
    std::vector<std::pair<long, long>> ranges;
    while (std::getline(file, line)) {
        if (line == "") break;

        int dashPos = line.find('-');
        long first = std::stol(line.substr(0, dashPos));
        long second = std::stol(line.substr(dashPos + 1));

        ranges.push_back(std::make_pair(first, second));
    }

    // Check IDs
    int fresh = 0;
    while (std::getline(file, line)) {
        long id = std::stol(line);
        for (const std::pair<long, long>& range : ranges) {
            if (id >= range.first && id <= range.second) {
                fresh++;
                break;
            }
        }
    }

    std::cout << "Solution: " << fresh << '\n';
}
