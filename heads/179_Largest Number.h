//
// Created by QiboLee on 2016/11/16 0016.
//

#ifndef LEETCODE_179_H
#define LEETCODE_179_H

#include "head.h"

bool great(const std::string &s1, const std::string &s2) {
    int min = std::min(s1.size(), s2.size());
    for (int i = 0; i < min; ++i) {
        if (s1[i] > s2[i]) {
            return true;
        } else if (s1[i] < s2[i]) {
            return false;
        }
    }
    return s1 + s2 > s2 + s1;
}

class Solution {
public:
    std::string largestNumber(std::vector<int> &nums) {

        std::vector<std::string> vec;
        vec.reserve(nums.size());
        for (auto &i:nums) {
            vec.push_back(std::to_string(i));
        }
        std::sort(vec.begin(), vec.end(), great);
        std::string s;
        s.reserve(vec.size() * 4);
        int i = 0;
        std::string zero("0");
        while (i < vec.size() && vec[i] == zero) {
            ++i;
        }
        while (i < vec.size()) {
            s.append(vec[i++]);
        }
        if (s.empty()) {
            return zero;
        }
        return s;
    }
};

#endif //LEETCODE_179_H
