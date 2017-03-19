//
// Created by Li,Qibo on 17/3/19.
//

#ifndef LEETCODE_NO306_H
#define LEETCODE_NO306_H

#include "head.h"

class Solution {
private:
    std::string add(const std::string &s1, const std::string &s2) {
        if (s1.empty()) {
            return s2;
        } else if (s2.empty()) {
            return s1;
        }
        std::string ret;
        ret.reserve(std::max(s1.size(), s2.size()));
        int tmp = 0, p1 = s1.size() - 1, p2 = s2.size() - 1;
        while (p1 >= 0 || p2 >= 0) {
            if (p1 >= 0) {
                tmp += s1[p1] - '0';
                --p1;
            }
            if (p2 >= 0) {
                tmp += s2[p2] - '0';
                --p2;
            }
            ret.push_back(tmp % 10 + '0');
            tmp /= 10;
        }
        if (tmp > 0) {
            ret.push_back(tmp + '0');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    bool check(const std::string &s1, const std::string &s2, const std::string &s) {
        std::string sum = add(s1, s2);
        if (sum == s) {
            return true;
        }
        if (sum.size() >= s.size()) {
            return false;
        }
        if (sum == s.substr(0, sum.size())) {
            return check(s2, sum, s.substr(sum.size()));
        } else {
            return false;
        }
    }

public:
    bool isAdditiveNumber(const std::string &num) {
        for (int i = 1; i < num.size() - 1; ++i) {
            for (int j = 1; j < num.size() - i; ++j) {
                std::string s1 = num.substr(0, i);
                if (s1.front() == '0' && i > 1) {
                    continue;
                }
                std::string s2 = num.substr(i, j);
                if (s2.front() == '0' && j > 1) {
                    continue;
                }
                std::string res = num.substr(i + j);
                if (res.front() == '0' && res.size() > 1) {
                    continue;
                }
                if (check(s1, s2, res)) {
                    return true;
                }
            }
        }
        return false;
    }
};

#endif //LEETCODE_NO306_H
