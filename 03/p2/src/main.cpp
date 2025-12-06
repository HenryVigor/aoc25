#include <fstream>
#include <iostream>
#include <string>

#include "input/getFirstFile.h"

const int DIGITS = 12;

int main() {
    std::ifstream file = getFirstFile();
    if (!file) return 1;

    std::string line;
    long total = 0;
    while (std::getline(file, line)) {
        std::string value;
        int index = -1;
        for (int i = 0; i < DIGITS; i++) {
            char digit = '0' - 1;
            for (int j = index + 1; j < line.length() + i - DIGITS + 1; j++) {
                if (line[j] > digit) {
                    digit = line[j];
                    index = j;
                }

                if (digit == '9') break;
            }

            value += digit;
        }

        total += std::stol(value);
    }

    std::cout << "Solution: " << total << '\n';
}
