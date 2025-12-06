#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "input/getFirstFile.h"

int main() {
    std::ifstream file = getFirstFile();
    if (!file) return 1;

    std::string line;
    int dial = 50;
    int zeros = 0;
    while (std::getline(file, line)) {
        bool fromZero = dial == 0;
        char dir = line[0];
        int delta = std::stoi(line.substr(1));

        dial = dir == 'R' ? dial + delta : dial - delta;

        while (dial > 99) {
            dial -= 100;
            zeros++;
        }

        while (dial < 0) {
            dial += 100;
            zeros++;
        }

        if (dir == 'L') {
            zeros += dial == 0;
            zeros -= fromZero;
        }
    }

    std::cout << "Solution: " << zeros << "\n";
}
