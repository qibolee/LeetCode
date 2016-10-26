#include "heads/head.h"
#include "heads/No132.h"

using namespace std;

int main() {

    clock_t start, finish;
    start = clock();
/**
 * your code
 */
//fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi
    Solution solution;
    cout << solution.minCut("aabbaaaa") << endl;

/**X
 * end
 */
    finish = clock();
    cout << "\nrun finished in " << 1.0 * (finish - start) / CLOCKS_PER_SEC << " (s)" << endl;

    return 0;
}

