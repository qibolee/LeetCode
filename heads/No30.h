//
// Created by QiboLee on 2016/9/23 0023.
//

#include "head.h"

#ifndef LEETCODE_NO30_H
#define LEETCODE_NO30_H

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string> &words) {
        std::vector<int> res;
        std::unordered_map<std::string, unsigned> total;
        for (std::string &s : words) {
            ++total[s];
        }
        unsigned len = words[0].size();
        for (unsigned i = 0; i + words.size() * len <= s.size(); ++i) {
            std::unordered_map<std::string, unsigned> tmp;
            unsigned k = 0;
            while (k < words.size()) {
                std::string word = s.substr(i + k * len, len);
                if (total.find(word) != total.end()) {
                    ++tmp[word];
                    if (tmp[word] > total[word]) {
                        break;
                    }
                } else {
                    break;
                }
                ++k;
            }
            if (k == words.size()) {
                res.push_back(i);
            }
        }
        return res;
    }
};

#endif //LEETCODE_NO30_H
