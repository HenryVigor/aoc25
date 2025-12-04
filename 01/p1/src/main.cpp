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
        char dir = line[0];
        int delta = std::stoi(line.substr(1, line.size() - 1));

        dial = (dir == 'R' ? dial + delta : dial - delta) % 100;

        zeros += dial == 0;
    }

    std::cout << "Solution: " << zeros << "\n";
}
