//
// Created by QiboLee on 2016/10/16 0016.
//

#include "head.h"

#ifndef LEETCODE_NO117_H
#define LEETCODE_NO117_H

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;

    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) {
            return;
        }
        TreeLinkNode *p = root, *q = root, *end = root;
        TreeLinkNode *tmp = nullptr;
        while (p) {
            if (p->left) {
                end->next = p->left;
                end = end->next;
            }
            if (p->right) {
                end->next = p->right;
                end = end->next;
            }
            if (p == q) {
                tmp = p->next;
                p->next = nullptr;
                p = tmp;
                q = end;
            } else {
                p = p->next;
            }
        }
        q->next = nullptr;
    }
};

#endif //LEETCODE_NO117_H
