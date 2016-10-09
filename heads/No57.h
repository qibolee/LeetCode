//
// Created by QiboLee on 2016/10/2 0002.
//

#ifndef LEETCODE_NO57_H
#define LEETCODE_NO57_H

// Definition for an interval.
struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
private:
    void merge(std::vector <Interval> &intervals, std::vector<Interval>::iterator it) {
        if (it != intervals.begin()) {
            auto p = it - 1;
            if (p->end >= it->start) {
                it = p;
            }
        }
        auto p = it + 1;
        for (; p != intervals.end(); ++p) {
            if (it->end >= p->start) {
                if (it->end < p->end) {
                    it->end = p->end;
                }
            } else {
                break;
            }
        }
        intervals.erase(it + 1, p);
    }

public:
    std::vector <Interval> insert(std::vector <Interval> &intervals, Interval newInterval) {
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        std::sort(intervals.begin(), intervals.end(), [](const Interval &par1, const Interval &par2) -> bool {
            return par1.start < par2.start;
        });
        auto iter = std::lower_bound(intervals.begin(), intervals.end(), newInterval, [](const Interval &par1,
                                                                                         const Interval &par2) {
            return par1.start < par2.start;
        });
        auto it = intervals.insert(iter, newInterval);
        merge(intervals, it);
        return intervals;

    }
};

#endif //LEETCODE_NO57_H
