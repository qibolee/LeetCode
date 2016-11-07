//
// Created by QiboLee on 2016/11/7 0007.
//

#ifndef LEETCODE_NO15_H
#define LEETCODE_NO15_H

#include "head.h"

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        std::vector<std::vector<int>> ret;
        if (nums.size() < 3) {
            return ret;
        }
        std::sort(nums.begin(), nums.end());
        if (nums.front() > 0 || nums.back() < 0) {
            return ret;
        }
        for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int p1 = i + 1;
            int p2 = nums.size() - 1;
            while (p1 < p2) {
                if (p1 > i + 1 && nums[p1] == nums[p1 - 1]) {
                    ++p1;
                    continue;
                }
                if (nums[p1] + nums[p2] < -nums[i]) {
                    ++p1;
                } else if (nums[p1] + nums[p2] > -nums[i]) {
                    --p2;
                } else {
                    std::vector<int> line{nums[i], nums[p1], nums[p2]};
                    if (ret.empty() || ret.back() != line) {
                        ret.push_back(std::move(line));
                    }
                    ++p1;
                    --p2;
                }
            }
        }
        return ret;
    }
};

#endif //LEETCODE_NO15_H
