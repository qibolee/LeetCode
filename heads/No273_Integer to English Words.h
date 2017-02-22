//
// Created by QiboLee on 2017/1/2 0002.
//

#ifndef LEETCODE_NO273_H
#define LEETCODE_NO273_H

#include "head.h"

class Solution {
private:
    const std::unordered_map<int, std::string> mp = {
            {0,  "Zero"},
            {1,  "One"},
            {2,  "Two"},
            {3,  "Three"},
            {4,  "Four"},
            {5,  "Five"},
            {6,  "Six"},
            {7,  "Seven"},
            {8,  "Eight"},
            {9,  "Nine"},
            {10, "Ten"},
            {11, "Eleven"},
            {12, "Twelve"},
            {13, "Thirteen"},
            {14, "Fourteen"},
            {15, "Fifteen"},
            {16, "Sixteen"},
            {17, "Seventeen"},
            {18, "Eighteen"},
            {19, "Nineteen"},
            {20, "Twenty"},
            {30, "Thirty"},
            {40, "Forty"},
            {50, "Fifty"},
            {60, "Sixty"},
            {70, "Seventy"},
            {80, "Eighty"},
            {90, "Ninety"}};

    std::string convert(int num) {
        std::string res;
        if (num < 10) {
            res.reserve(10);
            res.append(mp.at(num));
        } else if (num < 100) {
            res.reserve(20);
            if (num / 10 == 1) {
                res.append(mp.at(num));
            } else {
                if (num % 10 == 0) {
                    res.append(mp.at(num));
                } else {
                    res.append(mp.at(num / 10 * 10));
                    res.push_back(' ');
                    res.append(mp.at(num % 10));
                }
            }
        } else {
            res.reserve(40);
            res.append(mp.at(num / 100));
            res.append(" Hundred");
            if (num % 100 != 0) {
                res.push_back(' ');
                res.append(convert(num % 100));
            }
        }
        return res;
    }

public:
    std::string numberToWords(int num) {
        std::string res;
        res.reserve(50);
        int opt = 0;
        if (num >= 1000000000) {
            opt = num / 1000000000;
            res.append(convert(opt));
            res.append(" Billion");
        }
        if (num >= 1000000) {
            opt = (num / 1000000) % 1000;
            if (opt != 0) {
                if (!res.empty()) {
                    res.push_back(' ');
                }
                res.append(convert(opt));
                res.append(" Million");
            }
        }
        if (num >= 1000) {
            opt = (num / 1000) % 1000;
            if (opt != 0) {
                if (!res.empty()) {
                    res.push_back(' ');
                }
                res.append(convert(opt));
                res.append(" Thousand");
            }
        }
        opt = num % 1000;
        if (opt != 0) {
            if (!res.empty()) {
                res.push_back(' ');
            }
            res.append(convert(opt));
        }
        if (res.empty()) {
            return mp.at(0);
        }
        return res;
    }
};

#endif //LEETCODE_NO273_H
