//
// Created by QiboLee on 2016/10/13 0013.
//

#include "head.h"

#ifndef LEETCODE_NO91_H
#define LEETCODE_NO91_H

/**
 * dp solution
 * dp[i] = 0 and return 0 (if s[i] == '0' and s[i-1, i] don't in range [1...26])
 * dp[i] = dp[i - 1] (if s[i] != '0' and s[i-1, i] don't in range [1...26])
 * dp[i] = dp[i - 2] (if s[i] == '0' and s[i-1, i] does in range [1...26])
 * dp[i] = dp[i - 1] + dp[i - 2] (if s[i] != '0' and s[i-1, i] does in range [1...26])
 */

class Solution {
public:
    int numDecodings(std::string s) {
        if (s.empty() || s.front() == '0') {
            return 0;
        }
        if (s.size() == 1) {
            return 1;
        }

        std::vector<int> nums(s.size(), 0);
        nums[0] = 1;

        if (s[1] == '0') {

            if (s[0] > '2') {
                return 0;
            } else {
                nums[1] = 1;
            }

        } else {
            if (std::stoi(s.substr(0, 2)) < 27) {
                nums[1] = 2;
            } else {
                nums[1] = 1;
            }
        }

        for (int i = 2; i < s.size(); ++i) {

            if (s[i] == '0') {
                if (s[i - 1] > '2' || s[i - 1] == '0') {
                    return 0;
                } else {
                    nums[i] = nums[i - 2];
                }
            } else if (s[i - 1] == '0') {
                nums[i] = nums[i - 1];
            } else {
                if (std::stoi(s.substr(i - 1, 2)) < 27) {
                    nums[i] = nums[i - 1] + nums[i - 2];
                } else {
                    nums[i] = nums[i - 1];
                }
            }
        }
        return nums.back();
    }
};

#endif //LEETCODE_NO91_H
