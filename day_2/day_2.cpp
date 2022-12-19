//
// Created by johny on 19/12/2022.
//

#include <vector>
#include <fstream>
#include "day_2.h"

int correct_score(string fname) {
    static vector<vector<string>> coding = {{"B X\r", "C Y\r", "A Z\r"},
                                            {"A X\r", "B Y\r", "C Z\r"},
                                            {"C X\r", "A Y\r", "B Z\r"}};
    int score = 0;
    string line;
    ifstream file(fname);
    if (file.is_open()) {
        while (getline(file, line)) {
            for (int i = 0; i<3; i++) {
                for (int j = 0; j<3; j++) {
                    if (line == coding[i][j]) {
                        int adding = (i*3) + j + 1;
                        score += adding;
                    }
                }
            }
        }
    }
    return score;
}

