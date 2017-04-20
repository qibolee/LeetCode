#include "heads/head.h"
#include "heads/No220_Contains Duplicate III.h"
#include "String.h"
#include <fstream>
#include "Kara.h"
#include "KMP.h"


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

void q_sort(int *nums, int n) {
    if (n == 0 || n == 1) {
        return;
    }
    int tmp = nums[0];
    int p1 = 0, p2 = n - 1;
    bool fill_front = true;
    while (p1 < p2) {
        if (fill_front) {
            if (nums[p2] < tmp) {
                nums[p1] = nums[p2];
                ++p1;
                fill_front = false;
            } else {
                --p2;
            }
        } else {
            if (nums[p1] > tmp) {
                nums[p2] = nums[p1];
                --p2;
                fill_front = true;
            } else {
                ++p1;
            }
        }
    }
    nums[p1] = tmp;
    q_sort(nums, p1);
    q_sort(nums + p1 + 1, n - p1 - 1);

}

struct PairHash {
    int operator()(const pair<int, int> &par) const {
        return par.first ^ par.second;
    }
};

bool is_shui(int n) {
    int tmp = n;
    int sum = 0;
    while (tmp > 0) {
        sum += (tmp % 10) * (tmp % 10) * (tmp % 10);
        tmp /= 10;
    }
    return sum == n;
}

int main() {

    clock_t start, finish;
    start = clock();
/**
 * your code
 */






/**
 * end
 */
    finish = clock();
    cout << "\nrun finished in " << 1.0 * (finish - start) / CLOCKS_PER_SEC << " (s)" << endl;

    return 0;
}


