//
// Created by QiboLee on 2017/1/1 0001.
//

#ifndef LEETCODE_NO240_H
#define LEETCODE_NO240_H

#include "head.h"

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix.front().empty() || target < matrix.front().front() ||
            target > matrix.back().back()) {
            return false;
        }

        int row = matrix.size(), col = matrix.front().size();
        int i = row - 1, j = 0;
        while (i >= 0 && j < col) {
            if (target == matrix[i][j]) {
                return true;
            }
            if (target > matrix[i][j]) {
                ++j;
            } else if (target < matrix[i][j]) {
                --i;
            }
        }
        return false;
    }
};

#endif //LEETCODE_NO240_H
