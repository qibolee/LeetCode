//
// Created by QiboLee on 2016/10/14 0014.
//
#include "head.h"

#ifndef LEETCODE_NO93_H
#define LEETCODE_NO93_H

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> ret;
        if (s.size() < 4 || s.size() > 12) {
            return ret;
        }
        for (int a = 1; a < 4; ++a) {
            for (int b = 1; b < 4; ++b) {
                for (int c = 1; c < 4; ++c) {
                    for (int d = 1; d < 4; ++d) {
                        if (a + b + c + d == s.size()) {
                            int n1 = std::stoi(s.substr(0, a));
                            int n2 = std::stoi(s.substr(a, b));
                            int n3 = std::stoi(s.substr(a + b, c));
                            int n4 = std::stoi(s.substr(a + b + c, d));
                            if (n1 > 255 || n2 > 255 || n3 > 255 || n4 > 255) {
                                continue;
                            }
                            std::string line = std::to_string(n1) + "." + std::to_string(n2) + "." +
                                               std::to_string(n3) + "." + std::to_string(n4);
                            if (line.size() == s.size() + 3) {
                                ret.push_back(std::move(line));
                            }
                        }
                    }
                }
            }
        }
        return ret;

    }
};

#endif //LEETCODE_NO93_H
