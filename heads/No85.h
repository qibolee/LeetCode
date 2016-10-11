//
// Created by QiboLee on 2016/10/11 0011.
//

#ifndef LEETCODE_NO85_H
#define LEETCODE_NO85_H

#include "head.h"

class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>> &matrix) {

        if (matrix.empty()) {
            return 0;
        }
        std::vector<std::vector<int>> nums(matrix.size(), std::vector<int>(matrix.front().size(), 0));
        if (matrix.front().front() == 1) {
            nums.front().front() = 1;
        }
        for (int i = 1; i < matrix.front().size(); ++i) {//first row
            nums[0][i] = nums[0][i - 1] + (matrix[0][i] == 1);
        }
        for (int i = 1; i < matrix.size(); ++i) {//first col
            nums[i][0] = nums[i - 1][0] + (matrix[i][0] == 1);
        }
        for (int i = 1; i < matrix.size(); ++i) {//remain area
            for (int j = 1; j < matrix.size(); ++j) {
                nums[i][j] = nums[i - 1][j] + nums[i][j - 1] - nums[i - 1][j - 1] + (matrix[i][j] == 1);
            }
        }
        std::vector<std::pair<int, int>> seq;
        for (int h = nums.size(); h > 0; h--) {
            for (int w = nums.front().size(); w > 0; w--) {
                seq.push_back(std::pair<int, int>(h, w));
            }
        }
        std::sort(seq.begin(), seq.end(),
                  [](const std::pair<int, int> &par1, const std::pair<int, int> &par2) {
                      return par1.first * par1.second > par2.first * par2.second;
                  });
        int max = 0;
        bool need_to_exit = false;

        for (const std::pair<int, int> &par: seq) {
            int h = par.first;
            int w = par.second;
            for (int i = 0; i <= nums.size() - h; ++i) {
                for (int j = 0; j <= nums.front().size() - w; ++j) {
                    int cnt = nums[i + h - 1][j + w - 1];
                    if (i > 0 && j > 0) {
                        cnt -= nums[i - 1][j + w - 1] + nums[i + h - 1][j - 1] - nums[i - 1][j - 1];
                    } else if (i > 0) {
                        cnt -= nums[i - 1][j + w - 1];
                    } else if (j > 0) {
                        cnt -= nums[i + h - 1][j - 1];
                    }
                    if (cnt == h * w) {
                        max = cnt;
                        need_to_exit = true;
                        break;
                    }
                }
                if (need_to_exit) {
                    break;
                }
            }
            if (need_to_exit) {
                break;
            }
        }
        return max;
    }
};

#endif //LEETCODE_NO85_H
