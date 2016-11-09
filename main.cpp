#include "heads/head.h"
#include "heads/No15_3Sum.h"
#include "String.h"

using namespace std;


class A {
public:
    virtual void Print() { cout << "This is class A." << endl; }
};

class B : public A {
public:
    void Print() { cout << "This is class B." << endl; }
};

class C : public A {
public:
    void Print() { cout << "This is class C." << endl; }
};

void Handle(A *a) {
    cout << typeid(*a).name() << endl;
    if (typeid(*a) == typeid(A)) {
        cout << "I am a A truly." << endl;
    }
    else if (typeid(*a) == typeid(B)) {
        cout << "I am a B truly." << endl;
    }
    else if (typeid(*a) == typeid(C)) {
        cout << "I am a C truly." << endl;
    }
    else {
        cout << "I am alone." << endl;
    }
}

struct MT {
    int operator()(int i) {
        return i + 2;
    }
};


int main() {

    clock_t start, finish;
    start = clock();
/**
 * your code
 */
    MT mt;
    cout << mt(5) << endl;

    vector<int> nums = {1, 2, 3, 4, 5};
    sort(nums.begin(), nums.end(), [](const int &a, const int &b) -> bool { return a > b; });
    for_each(nums.begin(), nums.end(), [&](const int &i) { cout << i << " "; });
    cout << endl;

/**
 * end
 */
    finish = clock();
    cout << "\nrun finished in " << 1.0 * (finish - start) / CLOCKS_PER_SEC << " (s)" << endl;

    return 0;
}


