//
// Created by QiboLee on 2016/10/16 0016.
//

#include "head.h"

#ifndef LEETCODE_NO122_H
#define LEETCODE_NO122_H

class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        if (prices.size() < 2) {
            return 0;
        }

        int sum = 0;
        int min = prices.front(), max = min;
        for (int i = 1; i < prices.size(); ++i) {

            if (prices[i] > max) {
                max = prices[i];
            } else if (prices[i] < max) {
                sum += max - min;
                min = prices[i];
                max = min;
            }
        }
        return sum + max - min;
    }
};

#endif //LEETCODE_NO122_H
