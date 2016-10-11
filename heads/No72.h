//
// Created by QiboLee on 2016/10/9 0009.
//

#include "head.h"

#ifndef LEETCODE_NO72_H
#define LEETCODE_NO72_H


class Solution {

public:
    int minDistance(std::string word1, std::string word2) {

        if (word1.empty() || word2.empty()) {
            return std::max(word1.size(), word2.size());
        }
        if (word1.size() > word2.size()) {
            return minDistance(word2, word1);
        }

        std::vector<std::vector<int>> dp(word1.size(), std::vector<int>(word2.size(), 0));

        if (word1[0] != word2[0]) {
            dp[0][0] = 1;
        }
        for (int i = 1; i < word2.size(); ++i) {//first row
            if (dp[0][i - 1] == i - 1 || word1[0] == word2[i]) {
                dp[0][i] = i;
            } else {
                dp[0][i] = i + 1;
            }
        }
        for (int i = 1; i < word1.size(); ++i) {//first col
            if (dp[i - 1][0] == i - 1 || word1[i] == word2[0]) {
                dp[i][0] = i;
            } else {
                dp[i][0] = i + 1;
            }
        }
        for (int i = 1; i < word1.size(); ++i) {
            for (int j = 1; j < word2.size(); ++j) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::min({dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
                }
            }
        }

        return dp.back().back();
    }
};

#endif //LEETCODE_NO72_H
