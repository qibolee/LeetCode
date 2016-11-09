//
// Created by QiboLee on 2016/10/2 0002.
//

#include "head.h"

#ifndef LEETCODE_NO56_H
#define LEETCODE_NO56_H


// Definition for an interval.
struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    std::vector<Interval> merge(std::vector<Interval> &intervals) {
        if (intervals.size() < 2) {
            return intervals;
        }
        std::sort(intervals.begin(), intervals.end(), [](const Interval &par1, const Interval &par2) -> bool {
            if (par1.start != par2.start) {
                return par1.start < par2.start;
            } else {
                return par1.end < par2.end;
            }
        });
        std::stack<std::pair<int, int>> diff;
        diff.push(std::pair<int, int>(intervals.front().start, intervals.front().end));
        for (int i = 1; i < intervals.size(); ++i) {
            auto next = intervals[i];
            if (next.start <= diff.top().second && next.end > diff.top().second) {
                diff.top().second = next.end;
            } else if (next.start > diff.top().second) {
                diff.push(std::pair<int, int>(next.start, next.end));
            }
        }
        std::vector<Interval> res;
        res.reserve(diff.size());
        while (!diff.empty()) {
            auto par = diff.top();
            res.push_back(Interval(par.first, par.second));
            diff.pop();
        }
        std::sort(res.begin(), res.end(), [](const Interval &par1, const Interval &par2) -> bool {
            if (par1.start != par2.start) {
                return par1.start < par2.start;
            } else {
                return par1.end < par2.end;
            }
        });
        return res;
    }
};

#endif //LEETCODE_NO56_H
