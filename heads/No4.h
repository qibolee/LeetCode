//
// Created by QiboLee on 2016/11/4 0004.
//

#ifndef LEETCODE_NO4_H
#define LEETCODE_NO4_H

#include "head.h"

class Solution {
private:
    int getKth(const std::vector<int> &nums1, const std::vector<int> &nums2, size_t k) {
        if (nums1.size() > nums2.size()) {
            return getKth(nums2, nums1, k);
        }
        if (nums1.empty()) {
            return nums2[k - 1];
        }
        if (k == 1) {
            return std::min(nums1.front(), nums2.front());
        }
        size_t p1 = std::min(k / 2, nums1.size()), p2 = k - p1;
        if (nums1[p1 - 1] < nums2[p2 - 1]) {
            return getKth(std::vector<int>(nums1.begin() + p1, nums1.end()), nums2, p2);
        } else if (nums1[p1 - 1] > nums2[p2 - 1]) {
            return getKth(std::vector<int>(nums2.begin() + p2, nums2.end()), nums1, p1);
        } else {
            return nums1[p1 - 1];
        }
    }

public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
        size_t n = nums1.size() + nums2.size();
        if (n & 0x01) {
            return getKth(nums1, nums2, n / 2 + 1);
        }
        return (getKth(nums1, nums2, n / 2) + getKth(nums1, nums2, n / 2 + 1)) / 2.0;
    }
};

#endif //LEETCODE_NO4_H
