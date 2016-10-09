//
// Created by QiboLee on 2016/9/24 0024.
//

#include "head.h"

#ifndef LEETCODE_NO42_H
#define LEETCODE_NO42_H

class Solution {
public:
    int trap(std::vector<int> &height) {

        std::vector<int> tank(height);
        int p1 = 0, p2 = tank.size() - 1;
        while (p1 < tank.size() && tank[p1] == 0) {
            ++p1;
        }
        if (p1 == tank.size()) {
            return 0;
        }
        while (p2 >= 0 && tank[p2] == 0) {
            --p2;
        }
        int h = std::min(tank[p1], tank[p2]);
        for (int i = p1 + 1; i < p2; ++i) {
            tank[i] = std::max(tank[i], h);
        }
        while (p1 < p2) {
            if (tank[p1] == h) {
                ++p1;
            } else if (tank[p2] == h) {
                --p2;
            } else {
                h = std::min(tank[p1], tank[p2]);
                for (int i = p1 + 1; i < p2; ++i) {
                    tank[i] = std::max(tank[i], h);
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < tank.size(); ++i) {
            sum += tank[i] - height[i];
        }
        return sum;
    }
};

#endif //LEETCODE_NO42_H
