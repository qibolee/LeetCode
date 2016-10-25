//
// Created by QiboLee on 2016/10/24 0024.
//

#include "head.h"

#ifndef LEETCODE_NO131_H
#define LEETCODE_NO131_H

class Solution {
private:
    bool isPal(const std::string &s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }

public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> ret;
        if (s.empty()) {
            return ret;
        }
        int sum = 1;
        std::vector<decltype(ret)> dp(s.size() + 1, ret);
        for (int i = 1; i <= s.size(); ++i) {
            dp[i].reserve(sum);
            for (int len = 1; len <= i; ++len) {
                std::string tail = s.substr(i - len, len);
                if (!isPal(tail)) {
                    continue;
                }
                ret = dp[i - len];
                if (ret.empty()) {
                    dp[i].push_back(std::vector<std::string>(1, tail));
                } else {
                    for (auto &line : ret) {
                        line.push_back(tail);
                        dp[i].push_back(std::move(line));
                    }
                }
            }
            sum+=dp[i].size();
        }
        return dp.back();
    }
};

#endif //LEETCODE_NO131_H
