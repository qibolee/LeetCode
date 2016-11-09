//
// Created by QiboLee on 2016/11/8 0008.
//

#ifndef LEETCODE_NO135_H
#define LEETCODE_NO135_H

#include "head.h"

class Solution {
public:
    int candy(std::vector<int> &ratings) {
        if (ratings.empty()) {
            return 0;
        } else if (ratings.size() == 1) {
            return 1;
        } else if (ratings.size() == 2) {
            if (ratings.front() == ratings.back()) {
                return 2;
            }
            return 3;
        }

        std::vector<int> trend(ratings.size(), 0);
        std::vector<int> nums(ratings.size(), 0);

        if (ratings[0] > ratings[1]) {
            trend[0] = 1;
        } else {
            trend[0] = -1;
        }
        for (int i = 1; i < ratings.size() - 1; ++i) {
            if ((ratings[i] > ratings[i - 1] && ratings[i] >= ratings[i + 1]) ||
                (ratings[i] >= ratings[i - 1] && ratings[i] > ratings[i + 1])) {
                trend[i] = 1;
            }
            if (ratings[i] <= ratings[i - 1] && ratings[i] <= ratings[i + 1]) {
                trend[i] = -1;
            }
        }
        if (ratings[ratings.size() - 1] > ratings[ratings.size() - 2]) {
            trend[ratings.size() - 1] = 1;
        } else {
            trend[ratings.size() - 1] = -1;
        }
        for (int i = 0; i < trend.size(); ++i) {
            if (trend[i] != -1) {
                continue;
            }
            nums[i] = 1;
            for (int j = i - 1; j >= 0 && trend[j] == 0; --j) {
                nums[j] = nums[j + 1] + 1;
            }
            for (int j = i + 1; j < trend.size() && trend[j] == 0; ++j) {
                nums[j] = nums[j - 1] + 1;
            }
        }
        for (int i = 1; i < trend.size() - 1; ++i) {
            if (trend[i] != 1) {
                continue;
            }
            if (trend[i - 1] != 1 && trend[i + 1] != 1) {
                nums[i] = std::max(nums[i - 1], nums[i + 1]) + 1;
            } else if (trend[i - 1] == 1) {
                nums[i] = nums[i + 1] + 1;
            } else if (trend[i + 1] == 1) {
                nums[i] = nums[i - 1] + 1;
            }
        }
        if (trend.front() == 1) {
            nums.front() = nums[1] + 1;
        }
        if (trend.back() == 1) {
            nums.back() = nums[nums.size() - 2] + 1;
        }
        return std::accumulate(nums.begin(), nums.end(), 0);
    }
};

#endif //LEETCODE_NO135_H
