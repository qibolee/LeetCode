//
// Created by QiboLee on 2016/11/4 0004.
//

#ifndef LEETCODE_NO3_H
#define LEETCODE_NO3_H

#include "head.h"

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.size() < 2) {
            return s.size();
        }
        size_t max = 0;
        size_t beg = 0;
        std::unordered_map<char, size_t> mp;
        for (size_t i = 0; i < s.size(); ++i) {
            if (mp.find(s[i]) != mp.end() && mp[s[i]] >= beg) {
                max = std::max(max, i - beg);
                beg = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
        }
        max = std::max(max, s.size() - beg);
        return max;
    }
};

#endif //LEETCODE_NO3_H
