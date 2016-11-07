#include "heads/head.h"
#include "heads/No15.h"
#include "String.h"

using namespace std;

int get(int n) {
    int cnt = 0;
    while (n) {
        n &= n - 1;
        ++cnt;
    }
    return cnt;
}

int get2(int n) {
    int cnt = 0;
    for (int i = 0; i < 32; ++i) {
        if (n & 0x01) {
            ++cnt;
        }
        n >>= 1;
    }
    return cnt;
}

int main() {

    clock_t start, finish;
    start = clock();
/**
 * your code
 */

    vector<int> nums = {-1, -1, 1, 0, -4, 2};
    Solution().threeSum(nums);

/**X
 * end
 */
    finish = clock();
    cout << "\nrun finished in " << 1.0 * (finish - start) / CLOCKS_PER_SEC << " (s)" << endl;

    return 0;
}


