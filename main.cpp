#include "heads/head.h"
#include "heads/No220_Contains Duplicate III.h"
#include "String.h"
#include <fstream>
#include "Kara.h"
//#include "TestB.h"


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


string Encode(string in) {

    string ret;
    ret.reserve(32);
    int num = stoi(in);
    while (num != 0) {
        if (num % 2 == 1) {
            ret.push_back('1');
        } else {
            ret.push_back('0');
        }
        num /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;

}

string Decode(string in) {

    int ret = 0;
    for (char ch:in) {
        ret *= 16;
        if (ch >= '0' && ch <= '9') {
            ret += ch - '0';
        } else if (ch >= 'A' && ch <= 'F') {
            ret += ch - 'A';
        } else {
            return "false";
        }
    }

    return to_string(ret);

}


int main() {

    clock_t start, finish;
    start = clock();
/**
 * your code
 */


    int m, n;
    auto old_precision = cout.precision();
    cout.setf(ios::fixed);
    cout.precision(2);
    while (cin >> m >> n) {
        double sum = 0;
        double beg = n;
        while (m--) {
            sum += beg;
            beg = sqrt(beg);
        }
        cout << sum << endl;
    }
    cout.unsetf(ios::fixed);
    cout.precision(old_precision);


/**
 * end
 */
    finish = clock();
    cout << "\nrun finished in " << 1.0 * (finish - start) / CLOCKS_PER_SEC << " (s)" << endl;

    return 0;
}


