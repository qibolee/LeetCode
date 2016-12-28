//
// Created by QiboLee on 2016/12/28 0028.
//

#ifndef LEETCODE_NO233_H
#define LEETCODE_NO233_H

#include "head.h"

class Solution {
private:
    int getOne(int n) {
        int digit = n;
        int wide = 0;
        while (digit > 9) {
            digit /= 10;
            ++wide;
        }
        if (wide == 0) {
            return (n == 0 ? 0 : 1);
        }

        if (digit == 1) {
            int tmp = getOne(n / 10) - 1;
            return 10 * tmp + std::pow(10, wide - 1) + 1;
        } else {
            int tmp = getOne(n / digit) - 1;
            return tmp * digit + std::pow(10, wide);
        }
    }

public:
    int countDigitOne(int n) {
        if (n < 1) {
            return 0;
        }
        int res = 0;
        std::string s = std::to_string(n);
        int num = std::count_if(s.begin(), s.end(), [](char ch) { return ch != '0'; });
        while (num > 0) {
            auto p = std::find_if(s.rbegin(), s.rend(), [](char ch) { return ch != '0'; }).base();
            --p;
            std::string tail = s.substr(p - s.begin());
            *p = '0';
            int cnt = std::count_if(s.begin(), s.end(), [](char ch) { return ch == '1'; });
            res += cnt * std::stoi(tail) + getOne(std::stoi(tail));

            num = std::count_if(s.begin(), s.end(), [](char ch) { return ch != '0'; });

        }
        return res;
    }
};

#endif //LEETCODE_NO233_H
