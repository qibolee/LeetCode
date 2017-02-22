//
// Created by QiboLee on 2017/1/2 0002.
//

#ifndef LEETCODE_NO278_H
#define LEETCODE_NO278_H

#include "head.h"

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (isBadVersion(1)) {
            return 1;
        }
        int p1 = 1, p2 = n;
        while (p1 + 1 < p2) {
            int mid = (0LL + p1 + p2) / 2LL;
            if (isBadVersion(mid)) {
                p2 = mid;
            } else {
                p1 = mid;
            }
        }
        return p2;
    }
};

#endif //LEETCODE_NO278_H
