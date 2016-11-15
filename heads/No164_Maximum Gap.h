//
// Created by QiboLee on 2016/11/12 0012.
//

#ifndef LEETCODE_NO164_H
#define LEETCODE_NO164_H

#include "head.h"

class Solution {
public:
    int maximumGap(std::vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }
        if (nums.size() == 2) {
            return std::abs(nums.front() - nums.back());
        }
        int max = nums.front(), min = nums.front();
        for (int &i:nums) {
            if (i < min) {
                min = i;
            } else if (i > max) {
                max = i;
            }
        }
        if (min == max) {
            return 0;
        }
        int gap = (max - min) / (nums.size() - 1);
        if (gap == 0) {
            gap = 1;
        }
        int size = nums.size() - 1;

        std::vector<int> max_bts(size, 0);
        std::vector<int> min_bts(size, 0);
        std::vector<bool> fill(size, false);
        for (int &i:nums) {
            int p = (i - min) / gap;
            if (p >= size) {
                p = size - 1;
            }
            if (!fill[p]) {
                max_bts[p] = i;
                min_bts[p] = i;
                fill[p] = true;
            } else {
                if (i < min_bts[p]) {
                    min_bts[p] = i;
                } else if (i > max_bts[p]) {
                    max_bts[p] = i;
                }
            }
        }

        int maxGap = gap;
        int p = 0;
        while (!fill[p]) {
            ++p;
        }
        int last = max_bts[p];
        for (int i = p + 1; i < max_bts.size(); ++i) {
            if (fill[i]) {
                maxGap = std::max(maxGap, min_bts[i] - last);
                last = max_bts[i];
            }
        }
        return maxGap;
    }
};

#endif //LEETCODE_NO164_H
