//
// Created by QiboLee on 2016/11/8 0008.
//

#ifndef LEETCODE_NO138_H
#define LEETCODE_NO138_H

/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;

    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        using pNode = RandomListNode *;
        std::unordered_map <pNode, pNode> mp;
        pNode first = new RandomListNode(head->label);
        mp[head] = first;
        auto p = first;
        auto q = head;
        while (q->next) {
            p->next = new RandomListNode(q->next->label);
            p = p->next;
            q = q->next;
            mp[q] = p;
        }
        p = first;
        q = head;
        while (q) {
            if (q->random) {
                p->random = mp[q->random];
            }
            p = p->next;
            q = q->next;
        }
        return first;
    }
};

#endif //LEETCODE_NO138_H
