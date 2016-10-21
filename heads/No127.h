//
// Created by QiboLee on 2016/10/21 0021.
//

#include "head.h"

#ifndef LEETCODE_NO127_H
#define LEETCODE_NO127_H
//bfs solution
class Solution {
private:
    void getNext(std::string word, std::unordered_set<std::string> &wordList, std::queue<std::string> &toVisit) {
        for (int i = 0; i < word.size(); ++i) {
            char ch = word[i];
            for (int j = 0; j < 26; ++j) {
                word[i] = 'a' + j;
                if (wordList.find(word) != wordList.end()) {
                    toVisit.push(word);
                    wordList.erase(word);
                }
            }
            word[i] = ch;
        }
    }

public:
    int ladderLength(std::string beginWord, std::string endWord, std::unordered_set<std::string> &wordList) {
        wordList.erase(beginWord);
        wordList.insert(endWord);
        std::queue<std::string> toVisit;
        getNext(beginWord, wordList, toVisit);
        int dist = 2;
        while (!toVisit.empty()) {
            int size = toVisit.size();
            for (int i = 0; i < size; ++i) {
                std::string word = toVisit.front();
                toVisit.pop();
                if (word == endWord) {
                    return dist;
                }
                getNext(word, wordList, toVisit);
            }
            ++dist;
        }
        return 0;
    }
};

#endif //LEETCODE_NO127_H
