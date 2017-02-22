//
// Created by QiboLee on 2017/1/2 0002.
//

#ifndef LEETCODE_NO241_H
#define LEETCODE_NO241_H

#include "head.h"

struct Operate {
    char opt;
    int num;
    bool is_opt;

    Operate(char opt) {
        is_opt = true;
        this->opt = opt;
    }

    Operate(int num) {
        is_opt = false;
        this->num = num;
    }
};

class Solution {
private:
    std::vector<int> handle(const std::vector<Operate> &list) {
        if (list.size() == 1) {
            return std::vector<int>{list.front().num};
        } else if (list.size() == 3) {
            int num = 0;
            if (list[1].opt == '+') {
                num = list[0].num + list[2].num;
            } else if (list[1].opt == '-') {
                num = list[0].num - list[2].num;
            } else {
                num = list[0].num * list[2].num;
            }
            return std::vector<int>{num};
        }
        int len = (list.size() + 1) / 2;
        std::vector<int> res;
        res.reserve(len * len);
        for (int i = 1; i < len; ++i) {
            auto res1 = handle(std::vector<Operate>(list.begin(), list.begin() + i * 2 - 1));
            auto res2 = handle(std::vector<Operate>(list.begin() + i * 2, list.end()));
            for (int p1 = 0; p1 < res1.size(); ++p1) {
                for (int p2 = 0; p2 < res2.size(); ++p2) {
                    if (list[i * 2 - 1].opt == '+') {
                        res.push_back(res1[p1] + res2[p2]);
                    } else if (list[i * 2 - 1].opt == '-') {
                        res.push_back(res1[p1] - res2[p2]);
                    } else {
                        res.push_back(res1[p1] * res2[p2]);
                    }
                }
            }
        }
        return res;
    }

public:
    std::vector<int> diffWaysToCompute(std::string input) {
        if (input.empty()) {
            return std::vector<int>();
        }
        std::vector<Operate> list;
        auto q = input.begin();
        auto p = std::find_if(q, input.end(), [](char ch) { return ch == '+' || ch == '-' || ch == '*'; });
        while (p != input.end()) {
            std::string num = input.substr(q - input.begin(), p - q);
            list.push_back(Operate(std::stoi(num)));
            list.push_back(Operate(*p));
            q = p + 1;
            p = std::find_if(q, input.end(), [](char ch) { return ch == '+' || ch == '-' || ch == '*'; });
        }
        std::string num = input.substr(q - input.begin(), p - q);
        list.push_back(Operate(std::stoi(num)));
        auto res = handle(list);
        std::sort(res.begin(), res.end());
        return res;
    }
};

#endif //LEETCODE_NO241_H
