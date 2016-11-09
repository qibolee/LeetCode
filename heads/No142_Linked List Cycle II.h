//
// Created by QiboLee on 2016/10/29 0029.
//

#ifndef LEETCODE_NO142_H
#define LEETCODE_NO142_H

#include "unordered_set"

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        using pNode = ListNode *;
        pNode fast = head, slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};

#endif //LEETCODE_NO142_H
