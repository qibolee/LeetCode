//
// Created by QiboLee on 2016/10/10 0010.
//

#include "head.h"

#ifndef LEETCODE_NO76_H
#define LEETCODE_NO76_H

class Solution {
private:
    bool isGreat(std::unordered_map<char, int> mset1, std::unordered_map<char, int> mset2) {
        if (mset1.size() < mset2.size()) {
            return false;
        }
        for (auto beg = mset2.begin(); beg != mset2.end(); ++beg) {
            auto par = *beg;
            if (!(mset1.find(par.first) != mset1.end() && mset1[par.first] >= par.second)) {
                return false;
            }
        }
        return true;
    }

public:
    std::string minWindow(std::string s, std::string t) {

        if (s.empty() || t.empty()) {
            return "";
        }

        std::pair<int, int> min = {0, s.size() - 1};
        std::deque<int> ind;
        std::unordered_map<char, int> mset;
        std::unordered_map<char, int> curr;
        std::unordered_map<char, int> remain;

        for (char &ch:t) {
            ++mset[ch];
        }
        int p = 0;
        for (; p < s.size(); ++p) {
            if (mset.find(s[p]) != mset.end()) {
                ind.push_back(p);
                ++curr[s[p]];
                if (isGreat(curr, mset)) {
                    break;
                }
            }
        }
        if (p == s.size()) {
            return "";
        }
        min.first = ind.front();
        min.second = ind.back();

        std::for_each(curr.begin(), curr.end(), [&](const std::pair<char, int> &par) {
            if (par.second > mset[par.first]) {
                remain[par.first] = par.second - mset[par.first];
            }
        });
        while (remain.find(s[ind.front()]) != remain.end() && remain[s[ind.front()]] > 0) {
            --remain[s[ind.front()]];
            ind.pop_front();
        }
        if (ind.back() - ind.front() < min.second - min.first) {
            min.first = ind.front();
            min.second = ind.back();
        }
        for (int i = p + 1; i < s.size(); ++i) {
            if (mset.find(s[i]) != mset.end()) {

                ind.push_back(i);
                ++remain[s[i]];

                while (remain.find(s[ind.front()]) != remain.end() && remain[s[ind.front()]] > 0) {
                    --remain[s[ind.front()]];
                    ind.pop_front();
                }
                if (ind.back() - ind.front() < min.second - min.first) {
                    min.first = ind.front();
                    min.second = ind.back();
                }
            }
        }
        return s.substr(min.first, min.second - min.first + 1);
    }
};

#endif //LEETCODE_NO76_H
