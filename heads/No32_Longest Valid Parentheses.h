//
// Created by QiboLee on 2016/9/23 0023.
//

#include "head.h"

#ifndef LEETCODE_NO32_H
#define LEETCODE_NO32_H

class Solution {

public:
    int longestValidParentheses(std::string s) {
        if (s.size() < 2) {
            return 0;
        }
        int max = 0;
        std::stack<int> total;
        for (char &ch:s) {
            if (ch == '(') {
                total.push(-1);
            } else {
                if (total.empty()) {
                    total.push(1);
                } else {
                    if (total.top() == -1) {
                        total.pop();
                        int sum = 2;
                        while (!total.empty() && total.top() > 1) {
                            sum += total.top();
                            total.pop();
                        }
                        total.push(sum);
                        if (max < sum) {
                            max = sum;
                        }
                    } else if (total.top() > 1) {
                        int sum = total.top();
                        total.pop();
                        if (!total.empty() && total.top() == -1) {
                            total.pop();
                            sum += 2;
                            while (!total.empty() && total.top() > 1) {
                                sum += total.top();
                                total.pop();
                            }
                            total.push(sum);
                            if (max < sum) {
                                max = sum;
                            }
                        } else {
                            total.push(1);
                        }
                    } else {
                        total.push(1);
                    }
                }
            }
        }
        return max;

    }
};

#endif //LEETCODE_NO32_H
