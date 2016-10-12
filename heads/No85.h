//
// Created by QiboLee on 2016/10/11 0011.
//

#ifndef LEETCODE_NO85_H
#define LEETCODE_NO85_H

#include "head.h"

class Solution {
private:
    int largestRectangleArea(std::vector<int> &heights) {
        heights.push_back(0);
        std::stack<int> mt;
        int max = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!mt.empty() && heights[mt.top()] > heights[i]) {
                int ind = mt.top();
                mt.pop();

                int width = (mt.empty() ? i : i - mt.top() - 1);
                int tmp = heights[ind] * width;
                if (tmp > max) {
                    max = tmp;
                }
            }
            mt.push(i);
        }
        return max;
    }

public:
    int maximalRectangle(std::vector<std::vector<char>> &matrix) {

        if (matrix.empty()) {
            return 0;
        }
        int max = 0;
        std::vector<int> height(matrix.front().size(), 0);
        for (int i = 0; i < matrix.size(); ++i) {

            for (int j = 0; j < matrix.front().size(); ++j) {
                if (matrix[i][j] == '1') {
                    ++height[j];
                } else {
                    height[j] = 0;
                }
            }
            int tmp = largestRectangleArea(height);
            if (max < tmp) {
                max = tmp;
            }
        }

        return max;
    }
};

#endif //LEETCODE_NO85_H
