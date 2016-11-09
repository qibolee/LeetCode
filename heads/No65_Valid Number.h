//
// Created by QiboLee on 2016/10/3 0003.
//

#include "head.h"

#ifndef LEETCODE_NO65_H
#define LEETCODE_NO65_H

class Solution {
private:
    bool validChar(char ch) {
        if (ch == '-' || ch == '+' || ch == '.' || ch == 'e' || std::isdigit(ch)) {
            return true;
        }
        return false;
    }

    bool isInt(std::string s) {
        if (s.empty()) {
            return false;
        }
        if (s.front() == '-' || s.front() == '+') {
            s.erase(0, 1);
        }
        if (s.empty()) {
            return false;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (!std::isdigit(s[i])) {
                return false;
            }
        }
        return true;
    }

    bool isDouble(std::string s) {
        auto p = std::find(s.begin(), s.end(), 'e');
        if (p != s.end()) {
            bool tail = isInt(s.substr(p - s.begin() + 1));
            if (!tail) {
                return false;
            }
            s = s.substr(0, p - s.begin());
        }
        if (s.empty()) {
            return false;
        }
        if (s.front() == '+' || s.front() == '-') {
            s.erase(0, 1);
        }
        int dot = 0, num = 0;
        for (char ch:s) {
            if (ch == '.') {
                ++dot;
            } else if (std::isdigit(ch)) {
                ++num;
            }
        }
        if (dot > 1 || dot + num != s.size() || dot > num) {
            return false;
        }
        if (!s.empty() && s.front() == '.') {
            return false;
        }

        return true;
    }

public:
    bool isNumber(std::string s) {
        int p = -1;
        while (++p < s.size() && s[p] == ' ');
        s.erase(0, p);
        p = s.size();
        while (--p >= 0 && s[p] == ' ');
        s.erase(p + 1, s.size() - p - 1);

        for (int i = 0; i < s.size(); ++i) {
            if (!validChar(s[i])) {
                return false;
            }
        }
        if (isInt(s) || isDouble(s)) {
            return true;
        }
        return false;
    }
};

#endif //LEETCODE_NO65_H
