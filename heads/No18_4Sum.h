//
// Created by QiboLee on 2016/9/23 0023.
//

#include "head.h"

#ifndef LEETCODE_NO18_H
#define LEETCODE_NO18_H

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
        std::set<std::vector<int>> st;
        if (nums.size() < 4) {
            return std::vector<std::vector<int>>();
        }
        if (!is_sorted(nums.cbegin(), nums.cend())) {
            sort(nums.begin(), nums.end());
        }

        for (size_t i = 0; i < nums.size() - 3; ++i) {
            for (auto j = i + 1; j < nums.size() - 2; ++j) {
                const int sum = target - nums[i] - nums[j];
                auto p1 = j + 1, p2 = nums.size() - 1;
                while (p1 < p2) {
                    if (nums[p1] + nums[p2] == sum) {
                        st.insert(std::vector<int>({nums[i], nums[j], nums[p1],nums[p2]}));
                        ++p1;
                        --p2;
                        continue;
                    }
                    if (sum > 0 && nums[p1] > sum) {
                        break;
                    }
                    if (nums[p1] + nums[p2] < sum) {
                        ++p1;
                    } else {
                        --p2;
                    }
                }
                if (target - nums[i] > 0 && nums[j] > target - nums[i]) {
                    break;
                }
            }
        }
        return std::vector<std::vector<int>>(st.begin(), st.end());
    }
};

#endif //LEETCODE_NO18_H

