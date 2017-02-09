//
// Created by qiboli on 2017/2/9.
//

#ifndef LEETCODE_NO287_H
#define LEETCODE_NO287_H

#include "head.h"

class Solution {
public:
    int findDuplicate(std::vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] == nums[j]) {
                    return nums[i];
                }
            }
        }
        return 0;
    }
};

#endif //LEETCODE_NO287_H
