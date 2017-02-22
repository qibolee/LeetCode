//
// Created by QiboLee on 2016/11/19 0019.
//

#ifndef LEETCODE_NO213_H
#define LEETCODE_NO213_H

#include "head.h"

class Solution {
private:
    int rob2(const std::vector<int> &nums) {
        int a = nums[0];
        int b = std::max(nums[0], nums[1]);
        int c = 0;
        for (int i = 2; i < nums.size(); ++i) {
            c = std::max(b, a + nums[i]);
            a = b;
            b = c;
        }
        return b;
    }

public:
    int rob(std::vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums.front();
        }
        if (nums.size() == 2) {
            return std::max(nums[0], nums[1]);
        }
        return std::max(rob2(std::vector<int>(nums.begin(), nums.end() - 1)),
                        rob2(std::vector<int>(nums.begin() + 1, nums.end())));
    }
};

#endif //LEETCODE_NO213_H
