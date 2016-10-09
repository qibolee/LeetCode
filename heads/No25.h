//
// Created by QiboLee on 2016/9/23 0023.
//

#include "head.h"

#ifndef LEETCODE_NO25_H
#define LEETCODE_NO25_H

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    using pNode = ListNode *;

    std::pair<pNode, pNode> reverse(pNode beg, pNode end) {
        std::pair<pNode, pNode> res;
        res.second = beg;
        auto p = beg->next;
        beg->next = end;
        while (p != end) {
            auto q = p->next;
            p->next = beg;
            beg = p;
            p = q;
        }
        res.first = beg;
        return res;
    };

    std::pair<pNode, bool> nextN(pNode h, int step) {
        std::pair<pNode, bool> res;
        auto p = h;
        while (step--) {
            if (p == nullptr) {
                res.first = nullptr;
                res.second = false;
                return res;
            }
            p = p->next;
        }
        res.first = p;
        res.second = true;
        return res;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        size_t size = 0;
        if (k < 2 || head == nullptr || head->next == nullptr) {
            return head;
        }
        pNode p = head, q, tail;
        while (p) {
            ++size;
            p = p->next;
        }
        if (k > size) {
            return head;
        }
        p = head;
        q = p;
        auto par = nextN(q, k);
        while (par.second) {
            q = par.first;
            auto res = reverse(p, q);
            if (head == p) {
                head = res.first;
                tail = res.second;
            } else {
                tail->next = res.first;
                tail = res.second;
            }
            p = q;
            par = nextN(q, k);
        }
        return head;

    }
};

#endif //LEETCODE_NO25_H
