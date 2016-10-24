#include "heads/head.h"
#include "heads/No128.h"

using namespace std;

int main() {

    clock_t start, finish;
    start = clock();

    Solution solution;
    vector<int> vec = {1, 2, 0, 1};
    cout << solution.longestConsecutive(vec) << endl;

    finish = clock();
    cout << 1.0 * (finish - start) / CLOCKS_PER_SEC << " (s)" << endl;

    return 0;
}

