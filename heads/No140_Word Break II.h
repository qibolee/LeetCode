//
// Created by QiboLee on 2016/11/9 0009.
//

#ifndef LEETCODE_NO140_H
#define LEETCODE_NO140_H

#include "head.h"

class Solution {
private:
    bool
    possible(const std::string &s, std::unordered_set<std::string> &wordDict, std::vector<int> &dp, size_t &maxlen) {
        if (wordDict.empty()) {
            return false;
        }
        if (s.empty()) {
            return true;
        }
        dp.reserve(std::max(static_cast<int>(s.size() / 5), 16));
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

public:
    std::vector<std::string> wordBreak(const std::string &s, std::unordered_set<std::string> &wordDict) {
        std::vector<std::string> ret;
        std::vector<int> dp;
        size_t maxlen = 0;
        std::vector<std::vector<std::string>> sol;
        if (!possible(s, wordDict, dp, maxlen)) {
            return ret;
        }
        for (int i = 0; i < dp.size(); ++i) {
            sol.push_back(std::vector<std::string>());
            for (int k = i - 1; k >= 0; --k) {
                if (dp[i] - dp[k] > maxlen) {
                    break;
                }
                if (wordDict.find(s.substr(dp[k] + 1, dp[i] - dp[k])) != wordDict.end()) {
                    auto &vec = sol[k];
                    for (std::string &seg:vec) {
                        sol.back().push_back(seg + " " + s.substr(dp[k] + 1, dp[i] - dp[k]));
                    }
                }
            }
            if (dp[i] + 1 <= maxlen && wordDict.find(s.substr(0, dp[i] + 1)) != wordDict.end()) {
                sol.back().push_back(s.substr(0, dp[i] + 1));
            }
        }
        return sol.back();
    }
};

#endif //LEETCODE_NO140_H
