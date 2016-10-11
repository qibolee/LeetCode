//
// Created by QiboLee on 2016/10/10 0010.
//

#include "head.h"

#ifndef LEETCODE_NO84_H
#define LEETCODE_NO84_H

class Solution {
public:
    int largestRectangleArea(std::vector<int> &heights) {
        heights.push_back(0);
        std::stack<int> mt;
        int max = 0, tmp = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!mt.empty() && heights[mt.top()] > heights[i]) {
                int ind = mt.top();
                mt.pop();
                int width = (mt.empty() ? i : i - mt.top() - 1);
                tmp = heights[ind] * width;
                if (tmp > max) {
                    max = tmp;
                }
            }
            mt.push(i);
        }
        return max;
    }
};

#endif //LEETCODE_NO84_H
