//
// Created by QiboLee on 2016/10/15 0015.
//

#include "head.h"

#ifndef LEETCODE_NO95_H
#define LEETCODE_NO95_H

/**
 * Definition for a binary tree node.
 *
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    std::vector<TreeNode *> generateTrees(std::vector<int> nums) {
        std::vector<TreeNode *> ret;
        if (nums.empty()) {
            ret.push_back(nullptr);
            return ret;
        }
        ret.reserve(4 * nums.size() * nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            std::vector<int> nums1(nums.begin(), nums.begin() + i);
            std::vector<int> nums2(nums.begin() + i + 1, nums.end());
            std::vector<TreeNode *> left(std::move(generateTrees(nums1)));
            std::vector<TreeNode *> right(std::move(generateTrees(nums2)));
            for (int p1 = 0; p1 < left.size(); ++p1) {
                for (int p2 = 0; p2 < right.size(); ++p2) {
                    TreeNode *root = new TreeNode(nums[i]);
                    root->left = left[p1];
                    root->right = right[p2];
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }

public:
    std::vector<TreeNode *> generateTrees(int n) {
        if (n == 0) {
            return std::vector<TreeNode *>();
        }
        std::vector<int> nums;
        nums.reserve(n);
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }
        return generateTrees(nums);
    }
};

#endif //LEETCODE_NO95_H
