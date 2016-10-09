//
// Created by QiboLee on 2016/9/26 0026.
//

#ifndef LEETCODE_NO45_H
#define LEETCODE_NO45_H

class Solution {
private:
    int calculate(const std::vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }
        if (nums[0] + 2 > nums.size()) {
            return 1;
        }
        int min;
        std::vector<int> step(nums.size(), 0);
        for (int i = nums.size() - 2; i >= 0; --i) {
            min = nums.size();
            for (int j = i + 1; j < nums.size() && j <= i + nums[i]; ++j) {
                if (min > step[j]) {
                    min = step[j];
                }
            }
            step[i] = min + 1;
        }
        return step.front();
    }

public:
    int jump(std::vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }
        if (nums[0] + 2 > nums.size()) {
            return 1;
        }
        for (int i = 0; i + 1 < nums.size(); ++i) {
            for (int j = i + 1; j + 1 < nums.size() && j < i + nums[i]; ++j) {
                if (j + nums[j] <= i + nums[i] && nums[j] != 0) {
                    nums[j] = 0;
                }
            }
        }
        int cnt;
        for (int i = 0; i + 1 < nums.size(); ++i) {
            cnt = 0;
            for (int j = i + 1; j + 1 < nums.size() && j <= i + nums[i]; ++j) {
                if (nums[j] == 0) {
                    ++cnt;
                }
            }
            nums[i] -= cnt;
        }
        int p = 0;
        for (int i = 0; i + 1 < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[p] = nums[i];
                ++p;
            }
        }
        nums.resize(p + 1);
        return calculate(nums);
    }
};

#endif //LEETCODE_NO45_H
