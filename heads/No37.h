//
// Created by QiboLee on 2016/9/24 0024.
//

#include "head.h"

#ifndef LEETCODE_NO37_H
#define LEETCODE_NO37_H

/**
 * sudoku solver
 */
class Solution {
private:
    std::vector<char> solver(const std::vector<std::vector<char>> &board, int i, int j) {
        std::vector<char> res;
        bool exist[9];
        std::for_each(std::begin(exist), std::end(exist), [](bool &b) { b = false; });
        for (int k = 0; k < 9; ++k) {//current row
            if (board[i][k] != '.') {
                exist[board[i][k] - '1'] = true;
            }
        }
        for (int k = 0; k < 9; ++k) {//current col
            if (board[k][j] != '.') {
                exist[board[k][j] - '1'] = true;
            }
        }
        int i1 = i / 3 * 3, j1 = j / 3 * 3;
        for (int p1 = i1; p1 < i1 + 3; ++p1) {
            for (int p2 = j1; p2 < j1 + 3; ++p2) {
                if (board[p1][p2] != '.') {
                    exist[board[p1][p2] - '1'] = true;
                }
            }
        }
        for (int i = 0; i < 9; ++i) {
            if (!exist[i]) {
                res.push_back('1' + i);
            }
        }
        return res;
    }

    bool trave(std::vector<std::vector<char>> &board) {
        int cnt = 0;
        for (auto &line : board) {
            for (auto &ch:line) {
                if (ch == '.') {
                    ++cnt;
                }
            }
        }
        if (cnt == 0) {
            return true;
        }
        int min = 9, row, col;
        std::vector<char> possible;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    auto res = solver(board, i, j);
                    if (res.empty()) {
                        return false;
                    }
                    if (res.size() < min) {
                        min = res.size();
                        row = i;
                        col = j;
                        possible = std::move(res);
                    }
                }
            }
        }
        for (char ch : possible) {
            board[row][col] = ch;
            if (trave(board)) {
                return true;
            }
            board[row][col] = '.';
        }
        return false;
    }

public:
    void solveSudoku(std::vector<std::vector<char>> &board) {
        int cnt = 0;
        for (auto &line : board) {
            for (auto &ch:line) {
                if (ch == '.') {
                    ++cnt;
                }
            }
        }
        while (cnt > 0) {
            bool flg = false;
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    if (board[i][j] == '.') {
                        auto res = solver(board, i, j);
                        if (res.size() == 1) {
                            board[i][j] = res[0];
                            --cnt;
                            flg = true;
                        }
                    }
                }
            }
            if (!flg) {
                break;
            }
        }
        if (cnt > 0) {
            trave(board);
        }
    }
};

#endif //LEETCODE_NO37_H
