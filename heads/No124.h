//
// Created by QiboLee on 2016/10/21 0021.
//

#ifndef LEETCODE_NO124_H
#define LEETCODE_NO124_H

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
    //return <sum, max>
    std::pair<int, int> reBuild(TreeNode *root) {

        std::pair<int, int> ret1({0x80000000, 0}), ret2({0x80000000, 0}), ret({0, 0});
        if (root->left) {
            ret1 = reBuild(root->left);
        }
        if (root->right) {
            ret2 = reBuild(root->right);
        }
        ret.first = std::max({ret1.first, ret2.first, root->val, root->val + ret1.second, root->val + ret2.second,
                              root->val + ret1.second + ret2.second});
        ret.second = std::max({root->val, root->val + ret1.second, root->val + ret2.second});
        return ret;
    }

public:
    int maxPathSum(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return reBuild(root).first;
    }
};

#endif //LEETCODE_NO124_H
