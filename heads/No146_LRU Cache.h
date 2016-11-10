//
// Created by QiboLee on 2016/11/9 0009.
//

#ifndef LEETCODE_NO146_H
#define LEETCODE_NO146_H

#include "head.h"

class LRUCache {
private:
    int capacity;
    std::unordered_map<int, int> mp;
    std::unordered_map<int, int> times;
    std::vector<int> cache;
    int beg;

    void resize() {
        while (times.size() == capacity) {
            int tmp = cache[beg++];
            --times[tmp];
            if (times[tmp] == 0) {
                times.erase(tmp);
            }
        }
    }

public:
    LRUCache(int capacity) : capacity(capacity), beg(0) {
        mp.reserve(capacity * 2);
        times.reserve(capacity * 2);
        cache.reserve(capacity * 4);
    }

    int get(int key) {
        if (times.empty() || times.find(key) == times.end()) {
            return -1;
        }
        cache.push_back(key);
        ++times[key];
        return mp[key];
    }

    void set(int key, int value) {
        if (times.size() == capacity && times.find(key) == times.end()) {
            resize();
        }
        cache.push_back(key);
        ++times[key];
        mp[key] = value;
    }
};

#endif //LEETCODE_NO146_H
