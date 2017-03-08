//
// Created by QiboLee on 2017/3/8 0008.
//

#ifndef LEETCODE_NO299_H
#define LEETCODE_NO299_H

#include "head.h"

class Solution {
public:
    std::string getHint(std::string secret, std::string guess) {

        std::unordered_map<char, int> count1(10);
        std::unordered_map<char, int> count2(10);
        int right = 0;
        int wrong = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++right;
            } else {
                ++count1[secret[i]];
                ++count2[guess[i]];
            }
        }
        for (auto par:count1) {
            char key = par.first;
            wrong += std::min(count2[key], par.second);
        }
        std::string ret;
        ret.reserve(16);
        ret.append(std::to_string(right));
        ret.push_back('A');
        ret.append(std::to_string(wrong));
        ret.push_back('B');
        return ret;

    }
};

#endif //LEETCODE_NO299_H
