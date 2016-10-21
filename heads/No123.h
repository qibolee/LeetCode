//
// Created by QiboLee on 2016/10/16 0016.
//

#include "head.h"

#ifndef LEETCODE_NO123_H
#define LEETCODE_NO123_H

class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        if (prices.size() < 2) {
            return 0;
        }
        std::vector<std::vector<int>> dp(3, std::vector<int>(prices.size(), 0));
        for (int i = 1; i < dp.size(); ++i) {
            int beg = dp[i - 1][0] - prices[0];
            for (int j = 1; j < prices.size(); ++j) {
                dp[i][j] = std::max(dp[i][j - 1], prices[j] + beg);
                beg = std::max(beg, dp[i - 1][j] - prices[j]);
            }
        }

        return dp.back().back();
    }
};

#endif //LEETCODE_NO123_H
