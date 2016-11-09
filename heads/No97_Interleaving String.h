//
// Created by QiboLee on 2016/10/15 0015.
//

#include "head.h"

#ifndef LEETCODE_NO97_H
#define LEETCODE_NO97_H

class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        if (s3.empty()) {
            return true;
        }
        int cnt[256] = {};
        for (const char &ch:s1) {
            ++cnt[ch];
        }
        for (const char &ch:s2) {
            ++cnt[ch];
        }
        for (const char &ch:s3) {
            --cnt[ch];
        }
        if (std::any_of(std::begin(cnt), std::end(cnt), [](const int &i) { return i != 0; })) {
            return false;
        }


        std::vector<std::vector<bool>> dp(s1.size() + 1, std::vector<bool>(s2.size() + 1, false));

        //init first node
        dp[0][0] = true;
        //init first row
        for (int i = 1; i < dp.front().size(); ++i) {
            if (dp[0][i - 1] && s2[i - 1] == s3[i - 1]) {
                dp[0][i] = true;
            }
        }
        //init first col
        for (int i = 1; i < dp.size(); ++i) {
            if (dp[i - 1][0] && s1[i - 1] == s3[i - 1]) {
                dp[i][0] = true;
            }
        }
        //calculate remain
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp.front().size(); ++j) {
                if (s3[i + j - 1] == s1[i - 1] && s3[i + j - 1] != s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else if (s3[i + j - 1] != s1[i - 1] && s3[i + j - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i][j - 1];
                } else if (s3[i + j - 1] == s1[i - 1] && s3[i + j - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }

        return dp.back().back();
    }
};

#endif //LEETCODE_NO97_H
