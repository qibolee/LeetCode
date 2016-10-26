//
// Created by QiboLee on 2016/10/25 0025.
//

#ifndef LEETCODE_NO132_H
#define LEETCODE_NO132_H

#include "head.h"

class Solution {
public:
    int minCut(std::string s) {
        if (s.size() < 2) {
            return 0;
        }
        std::vector<std::vector<bool>> pal(s.size(), std::vector<bool>(s.size(), false));
        std::vector<int> lastTwoCut;
        std::vector<int> dp(s.size(), 0);
        lastTwoCut.push_back(0);
        pal.front().front() = true;
        for (int j = 1; j < pal.size(); ++j) {
            for (int i = j; i >= 0; --i) {
                if (s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }
        for (int i = 1; i < dp.size(); ++i) {
            if ((dp[i - 1] < 2) && pal[0][i]) {
                dp[i] = 0;
                lastTwoCut.clear();
                lastTwoCut.push_back(i);
                continue;
            }
            if (dp[i - 1] == 0) {
                dp[i] = 1;
                lastTwoCut.push_back(i);
            } else {
                int tmp = lastTwoCut.front();
                for (int j = std::max(tmp + tmp - i + 1, 1); j < i; ++j) {
                    if ((dp[j - 1] < dp[i - 1]) && pal[j][i]) {
                        dp[i] = dp[j - 1] + 1;
                        lastTwoCut.front() = j - 1;
                        lastTwoCut.back() = i;
                        break;
                    }
                }

                if (dp[i] == 0) {
                    for (int j = std::max(tmp + tmp - i + 1, 1); j < i; ++j) {
                        if ((dp[j - 1] == dp[i - 1]) && pal[j][i]) {
                            dp[i] = dp[j - 1] + 1;
                            lastTwoCut.front() = j - 1;
                            lastTwoCut.back() = i;
                            break;
                        }
                    }
                    if (dp[i] == 0) {
                        dp[i] = dp[i - 1] + 1;
                        lastTwoCut.front() = i - 1;
                        lastTwoCut.back() = i;
                    }
                }
            }
        }

        return dp.back();
    }
};

#endif //LEETCODE_NO132_H
