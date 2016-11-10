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
    std::list<int> cache;

    void setPro(int key) {
        auto p = std::find_if(cache.begin(), cache.end(), [&](const int &i) { return i == key; });
        cache.erase(p);
        cache.push_back(key);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.empty() || mp.find(key) == mp.end()) {
            return -1;
        }
        setPro(key);
        return mp[key];
    }

    void set(int key, int value) {
        if (mp.find(key) == mp.end()) {
            if (cache.size() < capacity) {
                cache.push_back(key);
                mp[key] = value;
            } else {
                mp.erase(cache.front());
                cache.pop_front();
                cache.push_back(key);
                mp[key] = value;
            }
        } else {
            mp[key] = value;
            setPro(key);
        }
    }
};

#endif //LEETCODE_NO146_H
