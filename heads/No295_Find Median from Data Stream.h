//
// Created by QiboLee on 2017/2/22 0022.
//

#ifndef LEETCODE_NO295_H
#define LEETCODE_NO295_H

#include "head.h"

class MedianFinder {
private:
    std::list<int> data;
    std::list<int>::iterator p1;
    std::list<int>::iterator p2;

    void insert_left(int num) {
        if (num <= data.front()) {
            data.push_front(num);
        } else {
            auto ptr = data.begin();
            while (num > *ptr) {
                ++ptr;
            }
            data.insert(ptr, num);
        }
    }

    void insert_right(int num) {
        if (num >= data.back()) {
            data.push_back(num);
        } else {
            auto ptr = p2;
            while (num >= *ptr) {
                ++ptr;
            }
            data.insert(ptr, num);
        }
    }

public:
    /** initialize your data structure here. */
    MedianFinder() : data(), p1(nullptr), p2(nullptr) {

    }

    void addNum(int num) {
        if (data.empty()) {
            data.push_back(num);
            p1 = data.begin();
            p2 = p1;
        } else {
            if (num <= *p1) {
                insert_left(num);
                if (p1 == p2) {
                    --p1;
                } else {
                    --p2;
                }
            } else if (num >= *p2) {
                insert_right(num);
                if (p1 == p2) {
                    ++p2;
                } else {
                    ++p1;
                }
            } else {
                data.insert(p2, num);
                ++p1;
                --p2;
            }
        }
    }

    double findMedian() {
        if (p1 == p2) {
            return *p1;
        } else {
            return (*p1 + *p2) / 2.0;
        }
    }
};

#endif //LEETCODE_NO295_H
