//
// Created by Li,Qibo on 17/3/19.
//

#ifndef LEETCODE_NO307_H
#define LEETCODE_NO307_H

#include "head.h"

class NumArray {
private:
    std::vector<int> sum;
    int limit;
    //<index, change>
    std::map<int, int> log_info;
public:
    NumArray(std::vector<int> nums) : sum(nums.size(), 0), limit(sqrt(nums.size())), log_info() {
        if (nums.empty()) {
            return;
        }
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum[i] = sum[i - 1] + nums[i];
        }
    }

    void update(int i, int val) {
        int origin = sum[i];
        if (i > 0) {
            origin -= sum[i - 1];
        }
        log_info[i] = val - origin;

        if (log_info.size() <= limit) {
            return;
        }
        auto beg = log_info.begin();
        int chg = 0;
        for (int j = beg->first; j < sum.size(); ++j) {
            if (beg != log_info.end() && j == beg->first) {
                chg += beg->second;
                ++beg;
            }
            sum[j] += chg;
        }
        log_info.clear();
    }

    int sumRange(int i, int j) {
        int p1 = std::max(i, 0);
        int p2 = std::min(static_cast<int>(sum.size()), j);

        int ret = sum[p2];
        if (p1 > 0) {
            ret -= sum[p1 - 1];
        }
        auto beg = log_info.begin();
        while (beg != log_info.end()) {
            if (beg->first >= p1 && beg->first <= p2) {
                ret += beg->second;
            }
            ++beg;
        }
        return ret;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

#endif //LEETCODE_NO307_H
