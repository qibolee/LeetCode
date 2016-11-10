//
// Created by QiboLee on 2016/11/10 0010.
//

#ifndef LEETCODE_NO150_H
#define LEETCODE_NO150_H

#include "head.h"

class Solution {
public:
    int evalRPN(std::vector<std::string> &tokens) {
        int nums[tokens.size() / 2 + 1];
        int size = 0;
        for (const std::string &s:tokens) {
            if (s.size() > 1 || s.front() > '/') {
                nums[size++] = std::stoi(s);
            } else {
                switch (s.front()) {
                    case '+':
                        nums[size - 2] = nums[size - 2] + nums[size - 1];
                        break;
                    case '-':
                        nums[size - 2] = nums[size - 2] - nums[size - 1];
                        break;
                    case '*':
                        nums[size - 2] = nums[size - 2] * nums[size - 1];
                        break;
                    case '/':
                        nums[size - 2] = nums[size - 2] / nums[size - 1];
                        break;
                }
                --size;
            }
        }
        return nums[0];
    }
};

#endif //LEETCODE_NO150_H
