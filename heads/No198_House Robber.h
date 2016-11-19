//
// Created by QiboLee on 2016/11/19 0019.
//

#ifndef LEETCODE_NO198_H
#define LEETCODE_NO198_H

#include "head.h"

class Solution {
public:
//dp solution,use O(n) space and O(n) time
    int rob(std::vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums.front();
        }
        std::vector<int> dp(nums.size(), 0);
        dp.front() = nums.front();
        dp[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < dp.size(); ++i) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp.back();
    }

//another solution,use O(1) space and O(n) time
    int rob2(std::vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums.front();
        }
        int a = nums.front();
        int b = std::max(nums[0], nums[1]);
        int c = 0;
        for (int i = 2; i < nums.size(); ++i) {
            c = std::max(b, a + nums[i]);
            a = b;
            b = c;
        }
        return b;
    }
};

#endif //LEETCODE_NO198_H
