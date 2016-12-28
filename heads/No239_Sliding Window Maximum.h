//
// Created by QiboLee on 2016/12/28 0028.
//

#ifndef LEETCODE_NO239_H
#define LEETCODE_NO239_H

#include "head.h"

class Solution {
private:
    void init(std::deque<int> &maxQueue, const std::vector<int> &nums, int k) {
        for (int i = k - 1; i >= 0; --i) {
            if (maxQueue.empty() || nums[i] >= maxQueue.front()) {
                maxQueue.push_front(nums[i]);
            }
        }
    }

public:
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
        if (k < 1 || k > nums.size()) {
            return std::vector<int>();
        }
        std::vector<int> res(nums.size() - k + 1);
        std::deque<int> maxQueue;
        init(maxQueue, nums, k);
        res.front() = maxQueue.front();
        for (int i = 1; i + k <= nums.size(); ++i) {
            if (nums[i - 1] == maxQueue.front()) {
                maxQueue.pop_front();
            }
            while (!maxQueue.empty() && maxQueue.back() < nums[i + k - 1]) {
                maxQueue.pop_back();
            }
            maxQueue.push_back(nums[i + k - 1]);
            res[i] = maxQueue.front();
        }
        return res;
    }
};

#endif //LEETCODE_NO239_H
