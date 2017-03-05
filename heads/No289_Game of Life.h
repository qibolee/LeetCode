//
// Created by QiboLee on 2017/2/22 0022.
//

#ifndef LEETCODE_NO289_H
#define LEETCODE_NO289_H

#include "head.h"

class Solution {
private:
    bool check(int i, int j, int row, int col) {
        return i >= 0 && j >= 0 && i < row && j < col;
    }

public:
    void gameOfLife(std::vector<std::vector<int>> &board) {
        if (board.empty()) {
            return;
        }
        std::vector<std::vector<int>> old(board);
        int row = old.size();
        int col = old.front().size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {

                int cnt = 0;
                for (int p1 = i - 1; p1 < i + 2; ++p1) {
                    for (int p2 = j - 1; p2 < j + 2; ++p2) {
                        if ((p1 != i || p2 != j) && check(p1, p2, row, col) && old[p1][p2] == 1) {
                            ++cnt;
                        }
                    }
                }

                if (old[i][j] == 0) {
                    if (cnt == 3) {
                        board[i][j] = 1;
                    }
                } else {
                    if (cnt < 2 || cnt > 3) {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
};

#endif //LEETCODE_NO289_H
