//
// Created by QiboLee on 2016/11/4 0004.
//

#ifndef LEETCODE_NO2_H
#define LEETCODE_NO2_H

#include "head.h"

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private :
    ListNode *add(ListNode *l1, ListNode *l2) {
        ListNode *p = l1;
        int tmp = p->val + l2->val;
        p->val = tmp % 10;
        tmp /= 10;

        while (p->next) {
            tmp += p->next->val;
            if (l2->next) {
                tmp += l2->next->val;
                l2 = l2->next;
            }
            p->next->val = tmp % 10;
            tmp /= 10;
            p = p->next;
        }
        if (tmp > 0) {
            p->next = new ListNode(tmp);
        }
        return l1;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int len1 = 0, len2 = 0;
        ListNode *p = l1;
        while (p) {
            ++len1;
            p = p->next;
        }
        p = l2;
        while (p) {
            ++len2;
            p = p->next;
        }
        if (len1 == 0) {
            return l2;
        } else if (len2 == 0) {
            return l1;
        }
        if (len2 > len1) {
            return add(l2, l1);
        } else {
            return add(l1, l2);
        }
    }
};

#endif //LEETCODE_NO2_H
