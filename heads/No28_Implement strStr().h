//
// Created by QiboLee on 2016/11/21 0021.
//

#ifndef LEETCODE_NO28_H
#define LEETCODE_NO28_H

#include "head.h"

class Solution {
private:
    std::vector<int> getNext(const std::string &s) {
        std::vector<int> next(s.size(), 0);
        next[0] = -1;
        next[1] = 0;
        for (int i = 2; i < next.size(); ++i) {
            int k = next[i - 1];
            while (k != -1 && s[k] != s[i - 1]) {
                k = next[k];
            }
            next[i] = k + 1;
        }
        return next;
    }

public:
    int strStr(const std::string &haystack, const std::string &needle) {
        if (needle.empty()) {
            return 0;
        }
        if (haystack.size() < needle.size()) {
            return -1;
        }
        if (needle.size() == 1) {
            for (int i = 0; i < haystack.size(); ++i) {
                if (haystack[i] == needle[0]) {
                    return i;
                }
            }
            return -1;
        }
        auto next = getNext(needle);
        int len1 = haystack.size();
        int len2 = needle.size();
        for (int i = 0, j = 0; i < len1 && j < len2;) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++i;
                ++j;
                if (j == len2) {
                    return i - j;
                }
            } else {
                j = next[j];
            }
        }
        return -1;
    }
};

#endif //LEETCODE_NO28_H
