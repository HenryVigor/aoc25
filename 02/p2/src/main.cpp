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
            for (int j = 1; j <= len / 2; j++) {
                if (len % j > 0) continue;

                int firstChunk = std::stoi(value.substr(0, j));
                bool match = false;
                for (int k = j; k < len; k += j) {
                    int chunk = std::stoi(value.substr(k, j));
                    if (chunk != firstChunk) break;
                    match = (k == len - j);
                }

                if (match) {
                    idSum += i;
                    break;
                }
            }
        }
    }

    std::cout << "Solution: " << idSum << '\n';
}
