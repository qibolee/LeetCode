//
// Created by QiboLee on 2016/12/24 0024.
//

#ifndef LEETCODE_NO220_H
#define LEETCODE_NO220_H

#include "head.h"

class Solution {
private:

    inline long long getBuketID(long long x, long long n) {
        return x < 0 ? (x - n + 1) / n : x / n;
    }

public:
    bool containsNearbyAlmostDuplicate(std::vector<int> &nums, int k, int t) {
        if (nums.size() < 2 || t < 0) {
            return false;
        }
        std::unordered_map<long long, long long> mp(k + 1);
        long long n = t + 1LL;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                mp.erase(getBuketID(nums[i - k - 1], n));
            }
            int buket = getBuketID(nums[i], n);
            if (mp.find(buket) != mp.end()) {
                return true;
            }
            if (mp.find(buket - 1) != mp.end() && nums[i] - mp[buket - 1] < n) {
                return true;
            }
            if (mp.find(buket + 1) != mp.end() && mp[buket + 1] - nums[i] < n) {
                return true;
            }
            mp[buket] = nums[i];
        }
        return false;
    }
};

#endif //LEETCODE_NO220_H
