//
// Created by QiboLee on 2016/9/24 0024.
//

#include "head.h"

#ifndef LEETCODE_NO44_H
#define LEETCODE_NO44_H


class Solution {
public:
    /**
     * '?' Matches any single character.
        '*' Matches any sequence of characters (including the empty sequence).
     * @param s
     * @param p
     * @return
     */
    bool isMatch(std::string s, std::string p) {
        if (p.empty()) {
            return s.empty();
        }
        std::string tmp;
        for (char &ch : p) {
            if (!(ch == '*' && !tmp.empty() && tmp.back() == '*')) {
                tmp.append(1, ch);
            }
        }
        p = tmp;
        if (s.empty()) {
            return p == "*";
        }
        const int row = p.size(), col = s.size() + 1;
        std::vector<std::vector<bool>> matrix;
        for (int i = 0; i < row; ++i) {
            std::vector<bool> line(col, false);
            matrix.push_back(line);
        }

        int t = s.size() - 1;

        switch (p.back()) {
            case '*':
                for (int i = 0; i <= t + 1; ++i) {
                    matrix[p.size() - 1][i] = true;
                }
                break;
            case '?':
                matrix[p.size() - 1][t] = true;
                --t;
                break;
            default:
                matrix[p.size() - 1][t] = (p.back() == s.back());
                --t;
                break;
        }
        if (p.size() == 1) {
            return matrix[0][0];
        }
        for (int i = p.size() - 2; i >= 0 && t + 1 >= 0; --i) {
            if (p[i] == '*') {
                while (t + 1 >= 0 && !matrix[i + 1][t + 1]) {
                    --t;
                }
                for (int j = 0; j <= t + 1; ++j) {
                    matrix[i][j] = true;
                }
            } else if (p[i] == '?') {
                for (int j = 0; j <= t; ++j) {
                    matrix[i][j] = matrix[i + 1][j + 1];
                }
                --t;
            } else {
                for (int j = 0; j <= t; ++j) {
                    matrix[i][j] = (p[i] == s[j] && matrix[i + 1][j + 1]);
                }
                --t;
            }
        }
        return matrix[0][0];
    }
};


#endif //LEETCODE_NO44_H
