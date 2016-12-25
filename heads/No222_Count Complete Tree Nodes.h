//
// Created by QiboLee on 2016/12/25 0025.
//

#ifndef LEETCODE_NO222_H
#define LEETCODE_NO222_H

#include "head.h"

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int base = 0;

    bool isExist(const TreeNode *root, int path) {
        auto p = root;
        int mb = base;
        while (mb) {
            if (path >= mb) {
                path -= mb;
                p = p->right;
            } else {
                p = p->left;
            }
            mb /= 2;
        }
        return p != nullptr;
    }

public:
    int countNodes(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        int h = 0;
        auto p = root;
        while (p) {
            ++h;
            p = p->left;
        }
        base = 1 << (h - 2);
        int p1 = 0, p2 = (base << 1) - 1;
        if (isExist(root, p2)) {
            return (1 << h) - 1;
        }

        int sum = 1 << (h - 1);
        while (p1 + 1 < p2) {
            int mid = (p1 + p2) / 2;
            if (isExist(root, mid)) {
                p1 = mid;
            } else {
                p2 = mid;
            }
        }
        return sum + p1;
    }
};

#endif //LEETCODE_NO222_H
