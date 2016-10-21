#include "heads/head.h"
#include "heads/No123.h"

using namespace std;

int main() {

    vector<int> vec = {1, 3, 5, 2, 4, 3, 7, 0, 3};
    Solution solution;
    cout << solution.maxProfit(vec) << endl;

    return 0;
}

