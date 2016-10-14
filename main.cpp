#include "heads/head.h"
#include "heads/No93.h"

using namespace std;

int main() {

    string str("010010");

    Solution solution;
    auto res = solution.restoreIpAddresses(str);
    for_each(res.begin(), res.end(), [](const string &s) { cout << s << endl; });

    return 0;
}

