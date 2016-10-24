//
// Created by QiboLee on 2016/10/24 0024.
//

#include "head.h"

#ifndef LEETCODE_NO126_H
#define LEETCODE_NO126_H

class Solution {
private:
    bool isPossible(std::unordered_set<std::string> &words, const std::string &target,
                    std::unordered_set<std::string> &wordList,
                    std::unordered_map<std::string, std::vector<std::string>> &next) {
        if (words.empty()) {
            return false;
        }
        for (auto beg = words.begin(); beg != words.end(); ++beg) {
            wordList.erase(*beg);
        }
        bool reach = false;
        std::unordered_set<std::string> word2;
        for (auto beg = words.begin(); beg != words.end(); ++beg) {
            std::string word = *beg;
            for (int i = 0; i < word.size(); ++i) {
                for (int j = 0; j < 26; ++j) {
                    word[i] = 'a' + j;
                    if (word != *beg) {
                        if (target == word) {
                            reach = true;
                            next[*beg].push_back(word);
                        } else if (!reach && wordList.find(word) != wordList.end()) {
                            next[*beg].push_back(word);
                            word2.insert(word);
                        }
                    }
                }
                word = *beg;
            }
        }
        return reach || isPossible(word2, target, wordList, next);
    }

    void
    getPaths(std::vector<std::string> &path, const std::string &target, std::vector<std::vector<std::string>> &paths,
             const std::unordered_map<std::string, std::vector<std::string>> &next) {
        if (path.back() == target) {
            paths.push_back(path);
            return;
        }
        if (next.find(path.back()) == next.end()) {
            return;
        }
        const std::vector<std::string> &ret = next.at(path.back());
        for (auto beg = ret.cbegin(); beg != ret.cend(); ++beg) {
            path.push_back(*beg);
            getPaths(path, target, paths, next);
            path.pop_back();
        }
    }

public:
    std::vector<std::vector<std::string>>
    findLadders(std::string beginWord, std::string endWord, std::unordered_set<std::string> &wordList) {
        std::unordered_set<std::string> words;
        std::unordered_map<std::string, std::vector<std::string>> next;
        words.insert(beginWord);
        wordList.erase(endWord);
        std::vector<std::vector<std::string>> paths;
        std::vector<std::string> path(1, beginWord);
        if (beginWord == endWord) {
            path.push_back(endWord);
            paths.push_back(path);
            return paths;
        }
        if (isPossible(words, endWord, wordList, next)) {
            getPaths(path, endWord, paths, next);
        }
        return paths;
    }
};

#endif //LEETCODE_NO126_H
