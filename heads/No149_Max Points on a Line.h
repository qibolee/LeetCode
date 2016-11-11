//
// Created by QiboLee on 2016/11/10 0010.
//

#ifndef LEETCODE_149_H
#define LEETCODE_149_H

#include "head.h"

/**
 * Definition for a point.
 */
struct Point {
    int x;
    int y;

    Point() : x(0), y(0) {}

    Point(int a, int b) : x(a), y(b) {}
};

struct PairHash {
    size_t operator()(const std::pair<int, int> &par) const {
        return par.first ^ par.second;
    }
};

class Solution {
private:
    int GCD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return GCD(b, a % b);
    }

public:
    int maxPoints(std::vector<Point> &points) {
        if (points.size() < 3) {
            return points.size();
        }
        int max = 2;
        for (int i = 0; i < points.size(); ++i) {

            int overlap = 0, maxlocal = 0;
            std::unordered_map<std::pair<int, int>, int, PairHash> lines((points.size() - i) << 1);
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++overlap;
                    continue;
                }
                int a = points[i].x - points[j].x;
                int b = points[i].y - points[j].y;
                int gcd = GCD(a, b);
                a /= gcd;
                b /= gcd;

                int tmp = ++lines[std::make_pair(a, b)];
                if (maxlocal < tmp) {
                    maxlocal = tmp;
                }
            }
            max = std::max(max, maxlocal + overlap + 1);
        }
        return max;
    }
};

#endif //LEETCODE_149_H
