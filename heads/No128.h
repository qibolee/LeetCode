//
// Created by QiboLee on 2016/10/24 0024.
//

#include "head.h"

#ifndef LEETCODE_NO128_H
#define LEETCODE_NO128_H

class Solution {
public:
    int longestConsecutive(std::vector<int> &nums) {

        if (nums.size() < 2) {
            return nums.size();
        }
        std::unordered_map<int, int> mp(nums.size());
        int max = 1;
        for (const int &i : nums) {
            if (mp.find(i) == mp.end()) {
                int left = 0;
                int right = 0;
                if (mp.find(i - 1) != mp.end()) {
                    left = mp[i - 1];
                }
                if (mp.find(i + 1) != mp.end()) {
                    right = mp[i + 1];
                }
                int sum = left + right + 1;
                max = std::max(max, sum);
                mp[i] = sum;
                mp[i - left] = sum;
                mp[i + right] = sum;
            }
        }
        return max;
    }
};

#endif //LEETCODE_NO128_H
