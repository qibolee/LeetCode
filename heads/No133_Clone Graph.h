//
// Created by QiboLee on 2016/11/8 0008.
//

#ifndef LEETCODE_NO133_H
#define LEETCODE_NO133_H

#include "head.h"

/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
    int label;
    std::vector<UndirectedGraphNode *> neighbors;

    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
private:
    std::unordered_map<int, UndirectedGraphNode *> mp;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (mp.find(node->label) != mp.end()) {
            return mp[node->label];
        } else {
            UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
            mp[root->label] = root;
            root->neighbors.reserve(node->neighbors.size());
            for (auto p : node->neighbors) {
                root->neighbors.push_back(cloneGraph(p));
            }
            return root;
        }
    }
};

#endif //LEETCODE_NO133_H
