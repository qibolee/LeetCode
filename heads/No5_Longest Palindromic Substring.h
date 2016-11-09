//
// Created by QiboLee on 2016/11/4 0004.
//

#ifndef LEETCODE_NO5_H
#define LEETCODE_NO5_H

#include "head.h"

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.size() < 2) {
            return s;
        }
        int size = s.size();
        int max = 1, beg = 0;
        int left = 0, right = 0;
        for (int i = 0; i + max / 2 < size;) {
            left = i - 1;
            right = i + 1;
            while (right < size && s[right] == s[right - 1]) {
                ++right;
            }
            i = right;
            while (left >= 0 && right < size && s[left] == s[right]) {
                --left;
                ++right;
            }
            if (max < right - left - 1) {
                max = right - left - 1;
                beg = left + 1;
            }
        }
        return s.substr(beg, max);
    }
};

#endif //LEETCODE_NO5_H
