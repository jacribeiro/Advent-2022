//
// Created by johny on 19/12/2022.
//
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int most_calories(string fname) {
    int sum = 0, max_cal = 0;
    string line;
    ifstream file(fname);
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line == "\r") {
                max_cal = max(sum, max_cal);
                sum = 0;
            } else {
                sum += stoi(line);
            }
        }
    }
    return max_cal;
}


int top3_calories(string fname) {
    int sum = 0;
    vector<int> top3 = {0, 0, 0};
    string line;
    ifstream file(fname);
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line == "\r") {
                auto it = top3.begin();
                while (it != top3.end()) {
                    if (sum > (*it)) {
                        it = top3.erase(it);
                        top3.push_back(sum);
                        sort(top3.begin(), top3.end());
                        break;
                    }
                    it++;
                }
                sum = 0;
            } else {
                sum += stoi(line);
            }
        }
    }
    int sum_top3 = 0;
    auto it = top3.begin();
    while (it != top3.end()) {
        sum_top3 += (*it);
        it++;
    }
    return sum_top3;
}
