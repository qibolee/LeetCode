//
// Created by QiboLee on 2017/3/19 0019.
//

#include "KMP.h"

#include "heads/head.h"

using namespace std;

//寻找前缀后缀最长公共元素长度
vector<int> KMP::getNext(const string &s) {
    vector<int> next(s.size(), 0);
    next[0] = -1;
    for (int i = 1; i < next.size(); ++i) {
        int p = i - 1;
        while (next[p] != -1) {
            if (s[i - 1] == s[next[p]]) {
                break;
            } else {
                p = next[p];
            }
        }
        next[i] = next[p] + 1;
    }
    return next;
}
