#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "input/getFirstFile.h"

int main() {
    std::ifstream file = getFirstFile();
    if (!file) return 1;

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    int lineLength = line.length();

    int lastTotal = -1;
    int total = 0;
    while (total > lastTotal) {
        lastTotal = total;

        for (int i = 0; i < lines.size(); i++) {
            std::string line = lines[i];

            for (int j = 0; j < lineLength; j++) {
                if (line[j] != '@') continue;

                int adjacentRolls = 0;
                for (int k = -1; k <= 1; k++) {
                    int y = i + k;

                    if (y > -1 && y < lines.size()) {
                        for (int l = -1; l <= 1; l++) {
                            int x = j + l;

                            if (
                                (k == 0 && l == 0) ||
                                x == -1 ||
                                x == lineLength
                            ) continue;

                            adjacentRolls += lines[y][x] == '@';
                            if (adjacentRolls == 4) break;
                        }
                    }

                    if (adjacentRolls == 4) break;
                    if (k == 1) {
                        total++;
                        lines[i][j] = '.';
                    }
                }
            }
        }
    }

    std::cout << "Solution: " << total << '\n';
}
