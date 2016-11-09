//
// Created by QiboLee on 2016/11/8 0008.
//

#ifndef LEETCODE_NO134_H
#define LEETCODE_NO134_H

class Solution {
public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
        if (gas.empty()) {
            return -1;
        }
        if (gas.size() == 1) {
            if (gas.front() >= cost.front()) {
                return 0;
            }
            return -1;
        }
        cost[0] = gas[0] - cost[0];
        for (int i = 1; i < cost.size(); ++i) {
            cost[i] = gas[i] - cost[i];
            if (cost[i] > 0 && cost[i - 1] < 0) {
                gas[i] = 1;
            } else {
                gas[i] = 0;
            }
        }
        if (cost.front() > 0 && cost.back() < 0) {
            gas[0] = 1;
        } else {
            gas[0] = 0;
        }
        for (int i = 0; i < gas.size(); ++i) {

            if (gas[i] == 1) {
                int sum = 0;
                for (int j = 0; j < gas.size(); ++j) {
                    sum += cost[(i + j) % gas.size()];
                    if (sum < 0) {
                        break;
                    }
                }
                if (sum >= 0) {
                    return i;
                }
            }
        }
        return -1;
    }
};

#endif //LEETCODE_NO134_H
