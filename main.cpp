#include "heads/head.h"
#include "heads/No149_Max Points on a Line.h"
#include "String.h"
#include <fstream>


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

struct VectorHash {
    size_t operator()(const std::vector<int> &v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

int main() {

    clock_t start, finish;
    start = clock();
/**
 * your code
 */
    vector<bool> vec;
    vec.push_back(true);
    auto var = String();
    cout << typeid(var).name() << endl;

/**
 * end
 */
    finish = clock();
    cout << "\nrun finished in " << 1.0 * (finish - start) / CLOCKS_PER_SEC << " (s)" << endl;

    return 0;
}


