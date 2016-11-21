//
// Created by QiboLee on 2016/11/20 0020.
//

#ifndef LEETCODE_NO363_H
#define LEETCODE_NO363_H

#include "head.h"

class Solution {
private:
    int maxSum(const std::vector<int> &nums, int k) {
        int best = INT32_MIN;
        int sum = 0;
        std::set<int> sumset;
        sumset.insert(0);
        for (const int &i:nums) {
            sum += i;
            auto iter = sumset.lower_bound(sum - k);
            if (iter != sumset.end()) {
                best = std::max(best, sum - *iter);
            }
            sumset.insert(sum);
        }
        return best;
    }

public:
    int maxSumSubmatrix(std::vector<std::vector<int>> &matrix, int k) {
        int row = matrix.size();
        int col = matrix.front().size();
        std::vector<int> curr(row, 0);
        int max = INT32_MIN;
        int currMax = 0;
        for (int i = 0; i < col; ++i) {
            std::fill(curr.begin(), curr.end(), 0);
            for (int j = i; j < col; ++j) {
                for (int p = 0; p < row; ++p) {
                    curr[p] += matrix[p][j];
                }
                currMax = maxSum(curr, k);
                if (currMax == k) {
                    return k;
                }
                if (max < currMax) {
                    max = currMax;
                }
            }
        }
        return max;
    }
};

#endif //LEETCODE_NO363_H
