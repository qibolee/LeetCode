//
// Created by QiboLee on 2016/11/8 0008.
//

#ifndef LEETCODE_N0139_H
#define LEETCODE_N0139_H

#include "head.h"

class Solution {
public:
    bool wordBreak(const std::string &s, std::unordered_set<std::string> &wordDict) {
        if (wordDict.empty()) {
            return false;
        }
        if (s.empty()) {
            return true;
        }
        std::vector<int> dp;
        dp.reserve(std::max(static_cast<int>(s.size() / 5), 16));
        size_t maxlen = 0;
        for (const std::string &str:wordDict) {
            if (maxlen < str.size()) {
                maxlen = str.size();
            }
        }
        for (int i = 0; i < s.size() && i < maxlen; ++i) {
            if (wordDict.find(s.substr(0, i + 1)) != wordDict.end()) {
                dp.push_back(i);
                break;
            }
        }
        if (dp.empty()) {
            return false;
        }
        for (int i = dp.back() + 1; i < s.size(); ++i) {
            for (int k = dp.size() - 1; k >= 0; --k) {
                int j = dp[k];
                if (i - j > maxlen) {
                    break;
                }
                if (wordDict.find(s.substr(j + 1, i - j)) != wordDict.end()) {
                    dp.push_back(i);
                    break;
                }
            }
            if (dp.back() != i && i < maxlen && (wordDict.find(s.substr(0, i + 1)) != wordDict.end())) {
                dp.push_back(i);
            }

        }
        return dp.back() == s.size() - 1;
    }
};

#endif //LEETCODE_N0139_H
