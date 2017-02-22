//
// Created by qiboli on 2017/2/7.
//

#ifndef LEETCODE_NO282_H
#define LEETCODE_NO282_H

#include "head.h"
#include <string>

class Solution {
private:
    void calculate(std::vector<std::string> &res, std::string path, const std::string &strNum, int target, int pos, long long value, long long multed) {
        if(pos == strNum.size()){
            if(value == target){
                res.push_back(path);
            }
        }
        for(int i = pos; i < strNum.size() && i - pos < 10; ++i){
            std::string tmp = strNum.substr(pos, i - pos + 1);
            if(tmp.size() > 1 && tmp.front() == '0'){
                return;
            }
            long long num = std::stoll(tmp);
            if(num < INT32_MIN || num > INT32_MAX){
                return;
            }
            if(pos == 0){
                calculate(res, std::to_string(num), strNum, target, i + 1, num, num);
            } else {
                calculate(res, path + "+" + std::to_string(num), strNum, target, i + 1, value + num, num);
                calculate(res, path + "-" + std::to_string(num), strNum, target, i + 1, value - num, -num);
                calculate(res, path + "*" + std::to_string(num), strNum, target, i + 1, value - multed + multed * num, multed * num);
            }

        }
    }

public:
    std::vector<std::string> addOperators(std::string num, int target) {
        std::vector<std::string> res;
        if (num.empty()) {
            return res;
        }
        if (num.size() == 1) {
            if (num.front() - '0' == target) {
                res.push_back(num);
                return res;
            }
            return res;
        }
        calculate(res, "", num, target, 0, 0, 0);

        return res;
    }
};

#endif //LEETCODE_NO282_H
