//
// Created by QiboLee on 2016/9/23 0023.
//

#include "head.h"

#ifndef LEETCODE_NO23_H
#define LEETCODE_NO23_H

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
        if (std::all_of(lists.cbegin(), lists.cend(), [](ListNode *ln) { return ln == nullptr; })) {
            return nullptr;
        }
        std::vector<int> res;
        res.reserve(lists.size());
        int row = 0, k = 0;
        while (true) {
            if (row == lists.size()) {
                break;
            }
            auto np = lists[row];
            while (np != nullptr) {
                res.push_back(np->val);
                np = np->next;
            }
            ++row;
        }
        sort(res.begin(), res.end());
        row = 0;
        k = 1;
        ListNode *h = new ListNode(res[0]), *p = h;
        while (k != res.size()) {
            if (row == lists.size()) {
                break;
            }
            while (lists[row] != nullptr) {
                p->next = lists[row];
                lists[row] = lists[row]->next;
                p = p->next;
                p->val = res[k++];
                if (k == res.size()) {
                    break;
                }
            }
            ++row;
        }
        p->next = nullptr;
        return h;
    }
};

#endif //LEETCODE_NO23_H
