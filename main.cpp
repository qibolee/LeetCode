#include "heads/head.h"
#include "heads/No72.h"

using namespace std;

int main() {

    string s("aac");
    string s1("aba"), s2("aab");
    Solution solution;
    cout << solution.minDistance(s, s1) << endl;
    cout << solution.minDistance(s, s2) << endl;

    cout << solution.maxCommon("mart", "karma") << endl;

    return 0;
}

