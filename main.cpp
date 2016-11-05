#include "heads/head.h"
#include "heads/No6.h"
#include "String.h"

using namespace std;


int main() {

    clock_t start, finish;
    start = clock();
/**
 * your code
 */

    cout << Solution().convert("ABCDE", 4) << endl;

/**X
 * end
 */
    finish = clock();
    cout << "\nrun finished in " << 1.0 * (finish - start) / CLOCKS_PER_SEC << " (s)" << endl;

    return 0;
}


