#include <fstream>
#include <iostream>
#include <string>

#include "input/getFirstFile.h"

int main() {
    std::ifstream file = getFirstFile();
    if (!file) return 1;

    std::string lines[3];

    // First line
    std::getline(file, lines[0]);
    std::getline(file, lines[1]);
    int lineLength = lines[0].length();

    // Get corners
    int total = (lines[0][0] == '@') + (lines[0][lineLength - 1] == '@');

    for (int i = 1; i < lineLength - 1; i++) {
        if (lines[0][i] != '@') continue;

        // Check current row
        int adjacentRolls = (lines[0][i - 1] == '@') + (lines[0][i + 1] == '@');

        // Check next row
        for (int j = -1; j <= 1; j++) {
            adjacentRolls += lines[1][i + j] == '@';
            if (adjacentRolls == 4) break;
            total += j == 1;
        }
    }

    // Middle lines
    int iLine = 1;
    while (std::getline(file, lines[(iLine + 1) % 3])) {

        for (int i = 0; i < lineLength; i++) {
            if (lines[iLine][i] != '@') continue;

            int adjacentRolls = 0;
            for (int j = -1; j <= 1; j++) {
                int y = (iLine + j + 3) % 3;

                for (int k = -1; k <= 1; k++) {
                    int x = i + k;

                    if ((j == 0 && k == 0) || x == -1 || x == lineLength) {
                        continue;
                    }

                    adjacentRolls += lines[y][x] == '@';
                    if (adjacentRolls == 4) break;
                }

                if (adjacentRolls == 4) break;
                total += j == 1;
            }
        }

        iLine = (iLine + 1) % 3;
    }

    // Last line
    // Get corners
    total += (lines[iLine][0] == '@') + (lines[iLine][lineLength - 1] == '@');

    for (int i = 1; i < lineLength - 1; i++) {
        if (lines[iLine][i] != '@') continue;

        // Check current row
        int adjacentRolls =
            (lines[iLine][i - 1] == '@') +
            (lines[iLine][i + 1] == '@')
        ;

        // Check previous row
        for (int j = -1; j <= 1; j++) {
            adjacentRolls += lines[(iLine + 2) % 3][i + j] == '@';
            if (adjacentRolls == 4) break;
            total += j == 1;
        }
    }

    std::cout << "Solution: " << total << '\n';
}
