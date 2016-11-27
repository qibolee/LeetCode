//
// Created by qibolee on 11/27/16.
//

#ifndef LEETCODE_NO218_H
#define LEETCODE_NO218_H

#include "head.h"

class Solution {
private:
    void insert(std::deque<std::pair<int, int>> &cad, const std::pair<int, int> &par) {
        auto p = std::lower_bound(cad.begin(), cad.end(), par,
                                  [](const std::pair<int, int> &par1, const std::pair<int, int> &par2) {
                                      return par1.first < par2.first;
                                  });
        if (p == cad.end() || p->first != par.first) {
            p = cad.insert(p, par);
        } else if (par.second > p->second) {
            p->second = par.second;
        } else {
            return;
        }
        if (p + 1 != cad.end()) {
            if (p->second <= (p + 1)->second) {
                cad.erase(p);
                return;
            }
        }
        while (p != cad.begin() && p->second >= (p - 1)->second) {
            p = cad.erase(p - 1);
        }
    }

    void push(std::vector<std::pair<int, int>> &res, std::deque<std::pair<int, int>> &cad,
              const std::pair<int, int> &wait, int &last) {

        if (!cad.empty() && cad.front().first < wait.first) {
            while (!cad.empty() && cad.front().first < wait.first) {
                std::pair<int, int> next;
                next.first = cad.front().first;
                cad.pop_front();
                if (cad.empty()) {
                    next.second = 0;
                } else {
                    next.second = cad.front().second;
                }
                last = next.second;
                res.push_back(next);
            }
        }
        if (wait.second > last) {
            res.push_back(wait);
            last = wait.second;
        }
    }

public:
    std::vector<std::pair<int, int>> getSkyline(std::vector<std::vector<int>> &buildings) {
        std::deque<std::pair<int, int>> cad;
        std::vector<std::pair<int, int>> res;
        int last = 0;
        std::pair<int, int> wait;
        bool isfirst = true;
        if (buildings.empty()) {
            return res;
        }
        for (auto &build:buildings) {
            int x1 = build[0];
            int x2 = build[1];
            int h = build[2];

            if (isfirst) {
                wait.first = x1;
                wait.second = h;
                isfirst = false;
                insert(cad, std::make_pair(x2, h));
                continue;
            }
            if (x1 != wait.first) {
                push(res, cad, wait, last);
                wait.first = x1;
                wait.second = h;

                while (!cad.empty() && cad.front().first < wait.first) {
                    std::pair<int, int> next;
                    next.first = cad.front().first;
                    cad.pop_front();
                    if (cad.empty()) {
                        next.second = 0;
                    } else {
                        next.second = cad.front().second;
                    }
                    last = next.second;
                    res.push_back(next);
                }

            } else {
                if (wait.second < h) {
                    wait.second = h;
                }
            }
            insert(cad, std::make_pair(x2, h));
        }
        push(res, cad, wait, last);
        while (!cad.empty()) {
            std::pair<int, int> next;
            next.first = cad.front().first;
            cad.pop_front();
            if (cad.empty()) {
                next.second = 0;
            } else {
                next.second = cad.front().second;
            }
            last = next.second;
            res.push_back(next);
        }
        return res;

    }
};

#endif //LEETCODE_NO218_H
