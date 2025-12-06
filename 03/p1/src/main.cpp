#include <fstream>
#include <iostream>
#include <string>

#include "input/getFirstFile.h"

int main() {
    std::ifstream file = getFirstFile();
    if (!file) return 1;

    std::string line;
    int total = 0;
    while (std::getline(file, line)) {
        std::string value;

        // Get largest digit from anywhere but the last space
        char digit = '0' - 1;
        int index = -1;
        for (int i = 0; i < line.length() - 1; i++) {
            if (line[i] > digit) {
                digit = line[i];
                index = i;
            }

            if (digit == '9') break;
        }

        value += digit;

        // Get largest digit after first found digit
        digit = '0';
        for (int i = index + 1; i < line.length(); i++) {
            if (line[i] > digit) digit = line[i];
            if (digit == '9') break;
        }

        value += digit;

        // Add value to total
        total += std::stoi(value);
    }

    std::cout << "Solution: " << total << '\n';
}
