#include "heads/head.h"
#include "heads/No85.h"

using namespace std;

int main() {

    Solution solution;
    vector<std::vector<char>> h = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };
    cout << solution.maximalRectangle(h) << endl;

    return 0;
}

