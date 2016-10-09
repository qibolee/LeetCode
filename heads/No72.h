//
// Created by QiboLee on 2016/10/9 0009.
//

#include "head.h"

#ifndef LEETCODE_NO72_H
#define LEETCODE_NO72_H


class Solution {
public:
    std::vector<std::string> getCommon(std::string s1, std::string s2) {
        std::vector<std::string> res;
        if (s1.empty() || s2.empty()) {
            return res;
        }
        if (s1.size() > s2.size()) {
            return getCommon(s2, s1);
        }
        std::vector<std::vector<int>> matrix;
        for (int i = 0; i < s1.size(); ++i) {
            matrix.push_back(std::vector<int>(s2.size(), 0));
            res.push_back(std::string());
        }
        if (s1[0] == s2[0]) {
            matrix[0][0] = 1;
            res[0].push_back(s1[0]);
        }
        for (int i = 1; i < s2.size(); ++i) {//first row
            if (matrix[0][i - 1] == 1) {
                matrix[0][i] = 1;
            } else if (s1[0] == s2[i]) {
                matrix[0][i] = 1;
                res[0].push_back(s1[0]);
            }
        }
        for (int i = 1; i < matrix.size(); ++i) {//first col
            if (matrix[i - 1][0] == 1) {
                matrix[i][0] = 1;
            } else if (s1[i] == s2[0]) {
                matrix[i][0] = 1;
                res[i].push_back(s2[0]);
            }
        }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (s1[i] == s2[j]) {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                    res[i].push_back(s1[i]);
                } else {
                    matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
                }
            }
        }
        int max = 0;
        for (int i = 1; i < res.size(); ++i) {
            if (res[i].size() > res[max].size()) {
                max = i;
            }
        }
        return res[max];
    }

    int minDistance(std::string word1, std::string word2, std::string common) {

        int p1 = 0, p2 = 0, q1 = 0, q2 = 0;
        int d1 = 0, d2 = 0;
        int res = 0;
        if (word1.empty() || word2.empty()) {
            return std::max(word1.size(), word2.size());
        }

        for (char ch:common) {
            q1 = word1.find(ch, p1);
            q2 = word2.find(ch, p2);

            d1 = q1 - p1;
            d2 = q2 - p2;
            res += std::max(d1, d2);

            p1 = q1 + 1;
            p2 = q2 + 1;
        }
        d1 = word1.size() - p1;
        d2 = word2.size() - p2;
        res += std::max(d1, d2);

        return res;
    }

public:
    int minDistance(std::string word1, std::string word2) {
        int p1 = 0, p2 = 0, q1, q2;
        int d1, d2;
        int res = 0, res2 = std::max(word1.size(), word2.size());
        if (word1.empty() || word2.empty()) {
            return res2;
        }

        std::string common = maxCommon(word1, word2);
        for (char ch:common) {
            q1 = word1.find(ch, p1);
            q2 = word2.find(ch, p2);

            d1 = q1 - p1;
            d2 = q2 - p2;
            res += std::max(d1, d2);

            p1 = q1 + 1;
            p2 = q2 + 1;
        }
        d1 = word1.size() - p1;
        d2 = word2.size() - p2;
        res += std::max(d1, d2);

        return std::min(res, res2);
    }
};

#endif //LEETCODE_NO72_H
