//
// Created by QiboLee on 2016/10/14 0014.
//
#include "head.h"

#ifndef LEETCODE_NO93_H
#define LEETCODE_NO93_H

class Solution {
private:
    bool getNext(std::vector<bool> &status, int &i1, int &i2, int &i3) {
        auto p1 = std::find(status.rbegin(), status.rend(), false);
        auto p2 = std::find(p1 + 1, status.rend(), true);
        if (p2 == status.rend()) {
            return false;
        }
        auto p = p2.base();
        *p2 = false;
        *p = true;
        auto cnt = std::count(p + 1, status.end(), true);
        std::fill_n(p + 1, cnt, true);
        std::fill(p + 1 + cnt, status.end(), false);


        return true;
    }

    bool check(int n1, int n2, int n3, int n4) {
        if (n1 > 0 && n1 < 256 && n2 > 0 && n3 < 256 && n3 > 0 && n3 < 256 && n4 > 0 && n4 < 256) {
            return true;
        }
        return false;
    }

public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> res;
        if (s.size() < 4) {
            return res;
        }
        std::vector<bool> status(s.size() - 1, false);
        status[0] = true;
        status[1] = true;
        status[2] = true;
        int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
        int p1 = 0, p2 = 1, p3 = 2;
        while (true) {

            n1 = std::stoi(s.substr(0, p1 + 1));
            n2 = std::stoi(s.substr(p1 + 1, p2 - p1));
            n3 = std::stoi(s.substr(p2 + 1, p3 - p2));
            n4 = std::stoi(s.substr(p3 + 1));
            if (check(n1, n2, n3, n4)) {
                std::string line =
                        std::to_string(n1) + string(".") + std::to_string(n2) + string(".") + std::to_string(n3) +
                        string(".") + std::to_string(n4);
                res.push_back(line);
            }

            if (!getNext(status, p1, p2, p3)) {
                break;
            }
        }
        return res;

    }
};

#endif //LEETCODE_NO93_H
