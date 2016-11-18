//
// Created by QiboLee on 2016/11/18 0018.
//

#ifndef LEETCODE_NO212_H
#define LEETCODE_NO212_H

#include "head.h"

struct Node {
    Node *next[26];
    std::string word;

    Node() : word("") {
        for (int i = 0; i < 26; ++i) {
            next[i] = nullptr;
        }
    }
};

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words) {
        std::vector<std::string> res;
        res.reserve(32);
        Node *root = buildTrie(words);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.front().size(); ++j) {
                dfs(board, i, j, root, res);
            }
        }
        std::sort(res.begin(), res.end());
        return res;
    }

private:
    void dfs(std::vector<std::vector<char>> &board, int i, int j, Node *root, std::vector<std::string> &res) {
        auto ch = board[i][j];
        auto p = root;
        if (ch == '.' || p->next[ch - 'a'] == nullptr) {
            return;
        }
        p = p->next[ch - 'a'];
        if (!p->word.empty()) {
            res.push_back(p->word);
            p->word = "";
        }
        board[i][j] = '.';
        if (i > 0) {
            dfs(board, i - 1, j, p, res);
        }
        if (j > 0) {
            dfs(board, i, j - 1, p, res);
        }
        if (i + 1 < board.size()) {
            dfs(board, i + 1, j, p, res);
        }
        if (j + 1 < board.front().size()) {
            dfs(board, i, j + 1, p, res);
        }
        board[i][j] = ch;
    }

    Node *buildTrie(const std::vector<std::string> &words) {
        Node *root = new Node();
        for (const auto &word:words) {
            auto p = root;
            for (auto &ch:word) {
                if (p->next[ch - 'a'] == nullptr) {
                    p->next[ch - 'a'] = new Node();
                }
                p = p->next[ch - 'a'];
            }
            p->word = word;
        }
        return root;
    }
};

#endif //LEETCODE_NO212_H
