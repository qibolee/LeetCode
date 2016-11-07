//
// Created by QiboLee on 2016/11/7 0007.
//

#ifndef LEETCODE_NO9_H
#define LEETCODE_NO9_H

#include "head.h"

class Solution {

public:
    bool isPalindrome(int x) {

        if (x < 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }
        long long n = x;
        long long s = 0;
        while (x) {
            s = s * 10 + x % 10;
            x /= 10;
        }
        return s == n;

    }
};


#endif //LEETCODE_NO9_H
