//
// Created by QiboLee on 2017/3/14 0014.
//

#ifndef LEETCODE_NO301_H
#define LEETCODE_NO301_H

#include "head.h"

class Solution {
public:
    Solution() {
        mp.reserve(10240);
    }

private:
    std::unordered_map<std::string, std::unordered_set<std::string>> mp;

    bool check(const std::string &s) {
        int cnt = 0;
        for (auto ch : s) {
            if (ch == '(') {
                ++cnt;
            } else if (ch == ')') {
                --cnt;
            }
            if (cnt < 0) {
                return false;
            }
        }
        return cnt == 0;
    }

    std::unordered_set<std::string> removeLR(const std::string &s, int left, int right) {
        std::unordered_set<std::string> ret;

        if (left == 0 && right == 0) {
            if (check(s)) {
                ret.insert(s);
            }
            mp[s] = ret;
            return ret;
        }
        if (mp.find(s) != mp.end()) {
            return mp[s];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (left > 0 && s[i] == '(') {
                auto tmp(s);
                tmp.erase(i, 1);
                if (mp.find(tmp) == mp.end()) {
                    auto res = removeLR(tmp, left - 1, right);
                    mp[tmp] = res;
                }
                ret.insert(mp[tmp].begin(), mp[tmp].end());
            } else if (right > 0 && s[i] == ')') {
                auto tmp(s);
                tmp.erase(i, 1);
                if (mp.find(tmp) == mp.end()) {
                    auto res = removeLR(tmp, left, right - 1);
                    mp[tmp] = res;
                }
                ret.insert(mp[tmp].begin(), mp[tmp].end());
            }
        }
        mp[s] = ret;
        return ret;
    }

public:
    std::vector<std::string> removeInvalidParentheses(std::string s) {
        std::vector<std::string> ret;
        if (s.empty()) {
            ret.push_back("");
            return ret;
        }
        int left = 0, right = 0;
        for (auto ch : s) {
            if (ch == '(') {
                ++left;
            } else if (ch == ')') {
                --left;
                if (left < 0) {
                    left = 0;
                    ++right;
                }
            }
        }
        if (left + right >= s.size()) {
            ret.push_back("");
            return ret;
        }

        mp.clear();
        auto res = removeLR(s, left, right);
        ret.insert(ret.end(), res.begin(), res.end());
        if (ret.empty()) {
            ret.push_back("");
        }
        return ret;
    }
};

#endif //LEETCODE_NO301_H
