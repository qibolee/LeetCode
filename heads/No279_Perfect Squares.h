//
// Created by QiboLee on 2017/1/2 0002.
//

#ifndef LEETCODE_NO279_H
#define LEETCODE_NO279_H

#include "head.h"

class Solution {
public:
    int numSquares(int n) {
        std::vector<int> dp(n + 1, 0);
        for (int i = 1; i < dp.size(); ++i) {
            int min = INT32_MAX;
            for (int j = 1; j * j <= i; ++j) {
                min = std::min(min, dp[i - j * j] + 1);
            }
            dp[i] = min;
        }
        return dp.back();
    }
};

#endif //LEETCODE_NO279_H
