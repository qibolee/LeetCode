//
// Created by QiboLee on 2016/10/15 0015.
//

#include "head.h"

#ifndef LEETCODE_NO99_H
#define LEETCODE_NO99_H

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
    std::vector<int> getArray(TreeNode *root) {
        std::vector<int> ret;
        if (root->left) {
            std::vector<int> left(std::move(getArray(root->left)));
            ret.insert(ret.end(), left.begin(), left.end());
        }
        ret.push_back(root->val);
        if (root->right) {
            std::vector<int> right(std::move(getArray(root->right)));
            ret.insert(ret.end(), right.begin(), right.end());
        }
        return ret;
    }

public:
    void recoverTree(TreeNode *root) {

        std::vector<int> ret = getArray(root);
        int p1 = 0, p2 = 0;
        for (int i = 1; i < ret.size(); ++i) {
            if (ret[i] < ret[i - 1]) {
                p1 = ret[i - 1];
                break;
            }
        }
        for (int i = ret.size() - 1; i > 0; i--) {
            if (ret[i - 1] > ret[i]) {
                p2 = ret[i];
                break;
            }
        }
        TreeNode *p = nullptr, *q = nullptr;
        int cnt = 0;
        auto h = root;
        //find p1
        while (true) {
            if (h->val == p1) {
                p = h;
                ++cnt;
                break;
            } else if (p2 < h->val) {
                h = h->left;
            } else if (p2 > h->val) {
                h = h->right;
            } else {
                q = h;
                ++cnt;
                if (p2 < p1) {
                    h = h->left;
                } else {
                    h = h->right;
                }
            }
        }
        if (cnt == 2) {
            p->val = p2;
            q->val = p1;
            return;
        }
        h = root;
        //find p2
        while (true) {
            if (h->val == p2) {
                q = h;
                break;
            } else if (p1 < h->val) {
                h = h->left;
            } else if (p1 > h->val) {
                h = h->right;
            } else {
                if (p1 < p2) {
                    h = h->left;
                } else {
                    h = h->right;
                }
            }
        }
        p->val = p2;
        q->val = p1;
    }
};

#endif //LEETCODE_NO99_H
