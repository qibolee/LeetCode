//
// Created by QiboLee on 2016/10/3 0003.
//

#include "head.h"

#ifndef LEETCODE_NO68_H
#define LEETCODE_NO68_H

class Solution {
private:
    std::string
    getLine(std::vector<std::string>::iterator beg, std::vector<std::string>::iterator end, int sum, int cnt,
            int width) {
        if (cnt == 1) {
            std::string line = *beg;
            std::fill_n(std::inserter(line, line.end()), width - sum, ' ');
            return line;
        } else {
            int space = width - sum;
            int avg = space / (cnt - 1);
            int mod = space % (cnt - 1);
            std::string line = *beg;
            auto p = beg + 1;
            for (int i = 0; i < mod; ++i) {
                line += std::string(avg + 2, ' ');
                line += *p;
                ++p;
            }
            while (p != end) {
                line += std::string(avg + 1, ' ');
                line += *p;
                ++p;
            }
            return line;
        }
    }

public:
    std::vector<std::string> fullJustify(std::vector<std::string> &words, int maxWidth) {
        std::vector<std::string> res;
        if (maxWidth == 0) {
            res.push_back("");
            return res;
        }
        int beg = 0;
        while (beg < words.size()) {
            int sum = 0, cnt = 0;
            int i = beg;
            while (i < words.size() && sum < maxWidth) {
                if (cnt != 0) {
                    ++sum;
                }
                sum += words[i].size();
                ++i;
                ++cnt;
            }
            if (sum > maxWidth) {
                sum -= words[--i].size() + 1;
                --cnt;
            }
            if (i == words.size()) {
                std::string line = words[beg];
                for (int k = beg + 1; k != i; ++k) {
                    line += " " + words[k];
                }
                line += std::string(maxWidth - line.size(), ' ');
                res.push_back(std::move(line));
            } else {
                res.push_back(std::move(getLine(words.begin() + beg, words.begin() + i, sum, cnt, maxWidth)));
            }
            beg = i;
        }


        return res;
    }
};

#endif //LEETCODE_NO68_H
