//
// Created by QiboLee on 2016/11/16 0016.
//

#ifndef LEETCODE_188_H
#define LEETCODE_188_H

#include "head.h"

class Solution {
private:
    int quitSolver(std::vector<int> &prices) {
        int tmp = 0, sum = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if ((tmp = prices[i] - prices[i - 1]) > 0) {
                sum += tmp;
            }
        }
        return sum;
    }

public:
    int maxProfit(int k, std::vector<int> &prices) {
        if (prices.size() < 2 || k < 1) {
            return 0;
        }
        if (k > prices.size() / 2) {
            return quitSolver(prices);
        }
        int *p1 = new int[prices.size()]();
        int *p2 = new int[prices.size()]();

        int min = prices.front();
        for (int i = 1; i < prices.size(); ++i) {
            p1[i] = std::max(p1[i - 1], prices[i] - min);
            if (prices[i] < min) {
                min = prices[i];
            }
        }
        for (int i = 1; i < k; ++i) {
            int max = -prices[0];
            for (int j = 1; j < prices.size(); ++j) {
                p2[j] = std::max(p2[j - 1], max + prices[j]);
                max = std::max(max, p1[j - 1] - prices[j]);
            }
            auto tmp = p1;
            p1 = p2;
            p2 = tmp;
        }
        return p1[prices.size() - 1];
    }
};

#endif //LEETCODE_188_H
