//
// Created by qiboli on 2017/2/9.
//

#ifndef LEETCODE_NO284_H
#define LEETCODE_NO284_H

#include "head.h"

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const std::vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    bool hasVal;
    int val;
public:
    PeekingIterator(const std::vector<int>& nums) : Iterator(nums), hasVal(false), val(0) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.

    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if(hasVal){
            return val;
        }
        hasVal = true;
        val = Iterator::next();
        return val;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if(hasVal){
            hasVal = false;
            return val;
        }
        return Iterator::next();
    }

    bool hasNext() const {
        return hasVal || Iterator::hasNext();
    }
};

#endif //LEETCODE_NO284_H
