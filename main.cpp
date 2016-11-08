#include "heads/head.h"
#include "heads/No15.h"
#include "String.h"

using namespace std;


int main() {

    clock_t start, finish;
    start = clock();
/**
 * your code
 */
    unordered_map<int, int *> mp;
    int *p = mp[0];
    p = mp[2];
    p = mp[3];
    p = mp[4];
    p = mp[5];
    cout << (p == nullptr) << endl;

/**X
 * end
 */
    finish = clock();
    cout << "\nrun finished in " << 1.0 * (finish - start) / CLOCKS_PER_SEC << " (s)" << endl;

    return 0;
}


