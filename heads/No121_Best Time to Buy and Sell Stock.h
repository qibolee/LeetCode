//
// Created by QiboLee on 2016/10/16 0016.
//

#include "head.h"

#ifndef LEETCODE_NO121_H
#define LEETCODE_NO121_H

class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int max = 0, p = prices.front();
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < p) {
                p = prices[i];
            } else {
                max = std::max(max, prices[i] - p);
            }
        }
        return max;
    }
};

#endif //LEETCODE_NO121_H
