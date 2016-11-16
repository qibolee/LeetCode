//
// Created by QiboLee on 2016/11/16 0016.
//

#ifndef LEETCODE_NO174_H
#define LEETCODE_NO174_H

#include "head.h"

class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int>> &dungeon) {
        if (dungeon.empty() || dungeon.front().empty()) {
            return 0;
        }
        int row = dungeon.size();
        int col = dungeon.front().size();
        int dp[row][col];

        //init last element
        dp[row - 1][col - 1] = 1;
        if (dp[row - 1][col - 1] + dungeon[row - 1][col - 1] < 1) {
            dp[row - 1][col - 1] -= dungeon[row - 1][col - 1];
        }

        //last row
        for (int i = col - 2; i >= 0; --i) {
            dp[row - 1][i] = dp[row - 1][i + 1] - dungeon[row - 1][i];
            if (dp[row - 1][i] < 1) {
                dp[row - 1][i] = 1;
            }
        }

        //last col
        for (int i = row - 2; i >= 0; --i) {
            dp[i][col - 1] = dp[i + 1][col - 1] - dungeon[i][col - 1];
            if (dp[i][col - 1] < 1) {
                dp[i][col - 1] = 1;
            }
        }

        //remain area
        for (int i = row - 2; i >= 0; --i) {
            for (int j = col - 2; j >= 0; --j) {

                if (dp[i + 1][j] < dp[i][j + 1]) {
                    dp[i][j] = dp[i + 1][j] - dungeon[i][j];
                    if (dp[i][j] < 1) {
                        dp[i][j] = 1;
                    }
                } else {
                    dp[i][j] = dp[i][j + 1] - dungeon[i][j];
                    if (dp[i][j] < 1) {
                        dp[i][j] = 1;
                    }
                }
            }
        }

        return dp[0][0];
    }
};

#endif //LEETCODE_NO174_H
