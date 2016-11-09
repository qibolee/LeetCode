//
// Created by QiboLee on 2016/10/12 0012.
//

#include "head.h"

#ifndef LEETCODE_NO87_H
#define LEETCODE_NO87_H

class Solution {

private:
    bool check(std::string s1, std::string s2) {
        std::vector<int> num(256, 0);
        for (int i = 0; i < s1.size(); ++i) {
            ++num[s1[i]];
            --num[s2[i]];
        }
        return std::all_of(num.begin(), num.end(), [](const int &i) { return i == 0; });
    }

public:
    bool isScramble(std::string s1, std::string s2) {

        if (s1 == s2) {
            return true;
        }
        if (!check(s1, s2)) {
            return false;
        }

        for (int i = 1; i < s1.size(); ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(s2.size() - i)) &&
                isScramble(s1.substr(i), s2.substr(0, s2.size() - i))) {
                return true;
            }
        }

        return false;
    }
};

#endif //LEETCODE_NO87_H
