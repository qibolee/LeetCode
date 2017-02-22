//
// Created by QiboLee on 2016/12/27 0027.
//

#ifndef LEETCODE_NO230_H
#define LEETCODE_NO230_H

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

    int analysis(TreeNode *const root, int k, int &res) {
        int left = 0, right = 0;
        if (root->left) {
            left = analysis(root->left, k, res);
        }
        if (left == -1) {
            return -1;
        }

        if (k == left + 1) {
            res = root->val;
            return -1;
        }
        if (root->right) {
            right = analysis(root->right, k - left - 1, res);
        }
        if (right == -1) {
            return -1;
        }
        return left + right + 1;
    }

public:

    int kthSmallest(TreeNode *root, int k) {
        int res = 0;
        analysis(root, k, res);
        return res;

    }
};

#endif //LEETCODE_NO230_H
