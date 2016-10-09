//
// Created by QiboLee on 2016/9/23 0023.
//

/**
 * Leetcode no.16
 */

#include "head.h"

#ifndef LEETCODE_NO16_H
#define LEETCODE_NO16_H

class Solution {
public:
    int threeSumClosest(std::vector<int> &nums, int target) {
        if (nums.size() < 3) {
            return 0;
        }
        int close = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 2; ++i) {
            const int tmp = target - nums[i];
            int p1 = i + 1, p2 = nums.size() - 1;
            while (p1 < p2) {
                if (abs(tmp - nums[p1] - nums[p2]) < abs(target - close)) {
                    close = nums[i] + nums[p1] + nums[p2];
                }
                if (tmp > 0 && nums[p1] > tmp) {
                    break;
                }
                if (nums[p1] + nums[p2] < tmp) {
                    ++p1;
                } else if (nums[p1] + nums[p2] > tmp) {
                    --p2;
                } else {
                    return target;
                }
            }
        }
        return close;
    }
};


#endif //LEETCODE_NO16_H
