#include "heads/head.h"
#include "heads/No126.h"

using namespace std;

int main() {

    clock_t start, finish;
    start = clock();

    string beginWord = "hit";
    string endWord = "cog";
    unordered_set<string> wordList({"hot", "dot", "dog", "lot", "log"});
    Solution solution;
    auto ret = solution.findLadders(beginWord, endWord, wordList);
    for (auto &line: ret) {
        for (auto &str:line) {
            cout << str << " ";
        }
        cout << endl;
    }

    finish = clock();
    cout << 1.0 * (finish - start) / CLOCKS_PER_SEC << " (s)" << endl;

    return 0;
}

