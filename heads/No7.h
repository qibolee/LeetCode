//
// Created by QiboLee on 2016/11/6 0006.
//

#ifndef LEETCODE_NO7_H
#define LEETCODE_NO7_H

#include "head.h"

class Solution {

public:
    int reverse(int x) {
        long long n = std::abs(static_cast<long long>(x));
        long long s = 0;

        while (n) {
            s = 10 * s + n % 10;
            n /= 10;
        }
        if (x < 0) {
            s = -s;
            if (s < -2147483648L) {
                return 0;
            }
            return s;
        }
        if (s > 2147483647L) {
            return 0;
        }
        return s;
    }
};

#endif //LEETCODE_NO7_H
