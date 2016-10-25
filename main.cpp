#include "heads/head.h"
#include "heads/No131.h"

using namespace std;

int main() {

    clock_t start, finish;
    start = clock();

    Solution solution;
    vector<vector<string>> vec = solution.partition("aabb");
    for (auto &line:vec) {
        for (auto &str:line) {
            cout << str << " ";
        }
        cout << endl;
    }

    finish = clock();
    cout << 1.0 * (finish - start) / CLOCKS_PER_SEC << " (s)" << endl;

    return 0;
}

