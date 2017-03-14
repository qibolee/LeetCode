//
// Created by QiboLee on 2017/3/14 0014.
//

#ifndef LEETCODE_NO304_H
#define LEETCODE_NO304_H

#include "head.h"

class NumMatrix {
private:
    std::vector<std::vector<int>> sum;
public:
    NumMatrix(const std::vector<std::vector<int>> &matrix) : sum(matrix.size(), std::vector<int>(
            matrix.size() > 0 ? matrix.front().size() : 0, 0)) {
        int cnt = 0;
        if (matrix.size() == 0 || matrix.front().size() == 0) {
            return;
        }
        // first col
        for (int i = 0; i < matrix.size(); ++i) {
            cnt += matrix[i][0];
            sum[i][0] = cnt;
        }
        // first row
        cnt = matrix[0][0];
        for (int j = 1; j < matrix.front().size(); ++j) {
            cnt += matrix[0][j];
            sum[0][j] = cnt;
        }
        // remain
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix.front().size(); ++j) {
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int A = sum[row2][col2];
        int A1 = 0, A2 = 0, A3 = 0;
        if (row1 > 0) {
            A1 = sum[row1 - 1][col2];
        }
        if (col1 > 0) {
            A2 = sum[row2][col1 - 1];
        }
        if (row1 > 0 && col1 > 0) {
            A3 = sum[row1 - 1][col1 - 1];
        }
        return A - A1 - A2 + A3;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

#endif //LEETCODE_NO304_H
