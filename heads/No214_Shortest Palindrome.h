//
// Created by QiboLee on 2016/11/20 0020.
//

#ifndef LEETCODE_NO214_H
#define LEETCODE_NO214_H

#include "head.h"

class Solution {
private:
    bool isPal(const std::string &s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }

public:
    std::string shortestPalindrome(const std::string &s) {
        if (isPal(s)) {
            return s;
        }
        int p = s.size() / 2 - 1;
        int p1 = p - 1;
        int p2 = p + 1;
        while (p1 >= 0 && s[p1] == s[p]) {
            --p1;
        }
        while (p2 < s.size() && s[p2] == s[p]) {
            ++p2;
        }
        if (p1 + 1 < s.size() - p2) {
            while (p1 >= 0) {
                if (s[p1] == s[p2]) {
                    --p1;
                    ++p2;
                } else {
                    break;
                }
            }
            if (p1 == -1) {
                std::string tail = s.substr(p2);
                std::reverse(tail.begin(), tail.end());
                return tail + s;
            }
        }

        for (int i = s.size() / 2 - 1; i >= 0;) {
            int front = i - 1;
            int back = i + 1;
            while (front >= 0 && s[front] == s[i]) {
                --front;
            }
            i = front;
            while (front >= 0) {
                if (s[front] == s[back]) {
                    --front;
                    ++back;
                } else {
                    break;
                }
            }
            if (front == -1) {
                std::string tail = s.substr(back);
                std::reverse(tail.begin(), tail.end());
                return tail + s;
            }

        }
        return s;
    }
};

#endif //LEETCODE_NO214_H
