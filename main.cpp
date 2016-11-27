#include "heads/head.h"
#include "heads/No218_The Skyline Problem.h"
#include "String.h"
#include <fstream>
#include "Kara.h"


using namespace std;


class A {
public:
    A(int i) {
        cout << "A(int)" << endl;
    }

private:
    typedef enum {
        a,
        b,
        c
    } Types;
};

class B : public A {
public:
    B() : A(3) {
        cout << "B()" << endl;
    }
};

struct Comp {
    bool operator()(const pair<int, int> &par1, const pair<int, int> &par2) {
        return par1.first < par2.first;
    }
};

int main() {

    clock_t start, finish;
    start = clock();
/**
 * your code
 */

    vector<vector<int>> vec = {
            {3,  9,  8},
            {5,  7,  10},
            {8,  11, 9},
            {13, 15, 3}
    };
    auto res = Solution().getSkyline(vec);
    for (auto &par:res) {
        cout << par.first << " " << par.second << endl;
    }



/**
 * end
 */
    finish = clock();
    cout << "\nrun finished in " << 1.0 * (finish - start) / CLOCKS_PER_SEC << " (s)" << endl;

    return 0;
}


