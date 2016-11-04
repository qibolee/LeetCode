#include "heads/head.h"
#include "heads/No1.h"
#include "String.h"

using namespace std;


int main() {

    clock_t start, finish;
    start = clock();
/**
 * your code
 */

    vector<int> nums = {2, 4, 3};
    auto ret = Solution().twoSum(nums, 5);
    cout << ret[0] << " " << ret[1] << endl;

/**X
 * end
 */
    finish = clock();
    cout << "\nrun finished in " << 1.0 * (finish - start) / CLOCKS_PER_SEC << " (s)" << endl;

    return 0;
}


