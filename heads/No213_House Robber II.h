//
// Created by QiboLee on 2016/11/19 0019.
//

#ifndef LEETCODE_NO213_H
#define LEETCODE_NO213_H

#include "head.h"

class Solution {
public:
    int rob(std::vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums.front();
        }
        int first1 = 0;
        int last1 = 0;
        int first2 = 0;
        int last2 = 0;
        int first3 = 0;
        int last3 = 0;

        std::vector<int> dp(nums.size(), 0);
        dp.front() = nums.front();
        if (nums[1] < nums[0]) {
            first2 = 0;
            last2 = 0;
            dp[1] = nums[0];
        } else {
            first2 = 1;
            last2 = 1;
            dp[1] = nums[1];
        }
        for (int i = 2; i < dp.size(); ++i) {

            if (dp[i - 1] > dp[i - 2] + nums[i]) {
                dp[i] = dp[i - 1];
                first3 = first2;
                last3 = last2;
            } else if (dp[i - 1] < dp[i - 2] + nums[i]) {
                dp[i] = dp[i - 2] + nums[i];
                first3 = first1;
                last3 = i;
            } else {
                if (first1 < first2) {
                    dp[i] = dp[i - 1];
                    first3 = first2;
                    last3 = last2;
                } else {
                    dp[i] = dp[i - 2] + nums[i];
                    first3 = first1;
                    last3 = i;
                }
            }
            first1 = first2;
            last1 = last2;
            first2 = first3;
            last2 = last3;
        }
        if()

    }
};

#endif //LEETCODE_NO213_H
