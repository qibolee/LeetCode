//
// Created by QiboLee on 2016/10/16 0016.
//

#include "head.h"

#ifndef LEETCODE_NO108_H
#define LEETCODE_NO108_H

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
    TreeNode *build(const std::vector<int> &nums) {
        int mid = (nums.size() - 1) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        if (mid > 0) {
            root->left = build(std::vector<int>(nums.begin(), nums.begin() + mid));
        }
        if (mid + 1 < nums.size()) {
            root->right = build(std::vector<int>(nums.begin() + mid + 1, nums.end()));
        }

        return root;
    }

public:
    TreeNode *sortedArrayToBST(std::vector<int> &nums) {
        if (nums.empty()) {
            return nullptr;
        }
        return build(nums);
    }
};

#endif //LEETCODE_NO108_H
