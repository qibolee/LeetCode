//
// Created by Li,Qibo on 17/4/20.
//

#ifndef LEETCODE_NO309_H
#define LEETCODE_NO309_H

#include "head.h"

class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        if (prices.size() < 2) {
            return 0;
        }
        std::vector<int> dp(prices.size(), 0);
        if (prices[1] > prices[0]) {
            dp[1] = prices[1] - prices[0];
        }
        int last_up = dp[1] > dp[0] ? 1 : 0;
        for (int i = 2; i < dp.size(); ++i) {
            dp[i] = dp[i - 1];
            if (prices[i] <= prices[i - 1]) {
                continue;
            }
            if (prices[i] > prices[last_up]) {
                dp[i] = dp[last_up] + prices[i] - prices[last_up];
            }

            if (last_up == i - 1 || last_up < i - 2) {
                dp[i] = std::max(dp[i], dp[i - 1] + prices[i] - prices[i - 1]);
            } else {
                int tmp;
                if (i > 2) {
                    tmp = std::max(dp[i - 2], dp[i - 3] + prices[i] - prices[i - 1]);
                } else {
                    tmp = std::max(dp[i - 2], prices[i] - prices[i - 1]);
                }
                dp[i] = std::max(dp[i], tmp);
            }

            if (dp[i] > dp[i - 1]) {
                last_up = i;
            }
        }
        return dp.back();
    }
};

#endif //LEETCODE_NO309_H
