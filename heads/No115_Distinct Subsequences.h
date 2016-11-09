//
// Created by QiboLee on 2016/10/16 0016.
//

#include "head.h"

#ifndef LEETCODE_NO115_H
#define LEETCODE_NO115_H

//calculate way transform s to t
class Solution {
public:
    int numDistinct(std::string s, std::string t) {

        if (t.empty()) {
            return 1;
        }
        if (s.size() < t.size()) {
            return 0;
        }

        std::vector<std::vector<int>> dp(t.size(), std::vector<int>(s.size(), 0));
        //init first element
        if (s.front() == t.front()) {
            dp[0][0] = 1;
        }
        //init first row
        for (int i = 1; i < dp.front().size(); ++i) {
            if (t[0] == s[i]) {
                dp[0][i] = dp[0][i - 1] + 1;
            } else {
                dp[0][i] = dp[0][i - 1];
            }
        }
        //calculate remain
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = i; j < dp.front().size(); ++j) {
                if (i == j) {
                    if (t[i] == s[j]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                } else {
                    if (t[i] == s[j]) {
                        dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = dp[i][j - 1];
                    }
                }
            }
        }
        return dp.back().back();
    }
};

#endif //LEETCODE_NO115_H
