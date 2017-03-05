//
// Created by QiboLee on 2017/3/5 0005.
//

#ifndef LEETCODE_NO297_H
#define LEETCODE_NO297_H

#include "head.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    using PTN = TreeNode *;

    int count_node(TreeNode *root){
        if (root == nullptr) {
            return 0;
        }
        return 1 + count_node(root->left) + count_node(root->right);
    }
    int count_node(string str) {
        int count = 0;
        for (char ch : str) {
            if (ch == '(') {
                ++count;
            }
        }
        return count;
    }
public:
//(parent_index, this_data, left or right), ...
//(-1,1,0)(0,2,0)(0,3,1)(2,4,0)(2,5,1)
// Encodes a tree to a single string.

    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }

        int len = count_node(root);
        string ret;
        ret.reserve(9 * len);

        int ind[len];
        PTN vec[len];
        int child[len];

        ind[0] = -1;
        vec[0] = root;
        child[0] = 0;

        int pindex = 0;
        int size = 1;
        while (size < len) {
            if (vec[pindex]->left != nullptr) {
                vec[size] = vec[pindex]->left;
                ind[size] = pindex;
                child[size] = 0;
                ++size;
            }
            if (vec[pindex]->right != nullptr) {
                vec[size] = vec[pindex]->right;
                ind[size] = pindex;
                child[size] = 1;
                ++size;
            }
            ++pindex;
        }
        for (int i = 0; i < len; ++i) {
            ret.push_back('(');
            ret.append(to_string(ind[i]));
            ret.push_back(',');
            ret.append(to_string(vec[i]->val));
            ret.push_back(',');
            ret.append(to_string(child[i]));
            ret.push_back(')');

        }
        //cout << ret << endl;
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        int len = count_node(data);
        PTN vec[len];

        int size = 0;
        for (int i = 0; i < data.size(); ) {
            int p = ++i;
            while (data[p] != ',') {
                ++p;
            }
            string str1 = data.substr(i, p - i);
            i = ++p;
            while (data[p] != ',') {
                ++p;
            }
            string str2 = data.substr(i, p - i);
            i = ++p;
            while (data[p] != ')') {
                ++p;
            }
            string str3 = data.substr(i, p - i);
            i = p + 1;

            int parent_ind = stoi(str1);
            int num = stoi(str2);
            int right = stoi(str3);
            //cout << "#" << parent_ind << "," << num << "," << right << endl;

            //TreeNode *ptr = new TreeNode(num);
            vec[size++] = new TreeNode(num);
            if (parent_ind != -1) {
                if (right == 0) {
                    vec[parent_ind]->left = vec[size - 1];
                } else {
                    vec[parent_ind]->right = vec[size - 1];
                }
            }
        }
        return vec[0];

    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

#endif //LEETCODE_NO297_H
