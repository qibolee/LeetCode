//
// Created by QiboLee on 2016/11/6 0006.
//

#ifndef LEETCODE_NO8_H
#define LEETCODE_NO8_H

#include "head.h"

class Solution {
public:
    int myAtoi(const std::string &str) {
        if (str.empty()) {
            return 0;
        }
        int p = -1;
        while (++p < str.size() && str[p] == ' ');
        bool isNeg = false;
        if (str[p] == '-') {
            isNeg = true;
            ++p;
        } else if (str[p] == '+') {
            ++p;
        }
        long long s = 0;
        while (p < str.size() && std::isdigit(str[p])) {
            s = s * 10 + str[p] - '0';
            ++p;
            if (s > 2147483648L) {
                break;
            }
        }
        if (isNeg) {
            s = -s;
            if (s < -2147483648L) {
                return -2147483648;
            }
            return s;
        }
        if (s > 2147483647L) {
            return 2147483647;
        }
        return s;
    }
};

#endif //LEETCODE_NO8_H
