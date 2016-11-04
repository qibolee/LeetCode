//
// Created by QiboLee on 2016/11/4 0004.
//

#ifndef LEETCODE_NO1_H
#define LEETCODE_NO1_H

#include "head.h"

class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::vector<int> tmp(nums.begin(), nums.end());
        sort(tmp.begin(), tmp.end());
        int p1 = 0, p2 = tmp.size() - 1;
        while (p1 < p2) {
            if (tmp[p1] + tmp[p2] < target) {
                ++p1;
            } else if (tmp[p1] + tmp[p2] > target) {
                --p2;
            } else {
                break;
            }
        }
        std::vector<int> ret;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == tmp[p1]) {
                ret.push_back(i);
            } else if (nums[i] == tmp[p2]) {
                ret.push_back(i);
            }
            if (ret.size() == 2) {
                break;
            }
        }
        if (ret[0] > ret[1]) {
            p1 = ret[0];
            ret[0] = ret[1];
            ret[1] = p1;
        }
        return ret;
    }
};

#endif //LEETCODE_NO1_H
