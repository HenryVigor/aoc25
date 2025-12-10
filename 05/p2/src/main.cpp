#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "input/getFirstFile.h"

int main() {
    std::ifstream file = getFirstFile();
    if (!file) return 1;

    // Get listed ranges and sort by first
    std::string line;
    std::vector<std::pair<long, long>> ranges;
    while (std::getline(file, line)) {
        if (line == "") break;

        int dashPos = line.find('-');
        long first = std::stol(line.substr(0, dashPos));
        long second = std::stol(line.substr(dashPos + 1));

        ranges.push_back(std::make_pair(first, second));
    }
    std::sort(ranges.begin(), ranges.end());

    // Get total number of fresh IDs
    long high = 0;
    long total = 0;
    for (const std::pair<long, long>& range : ranges) {
        if (range.second <= high) continue;

        total += range.second - (range.first > high ? range.first - 1 : high);
        high = range.second;
    }

    std::cout << "Solution: " << total << '\n';
}
