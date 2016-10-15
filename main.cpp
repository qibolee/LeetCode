#include "heads/head.h"
#include "heads/No97.h"

using namespace std;

int main() {


    string s1 = "aabcc";
    string s2 = "dbbca";

    string s3 = "aadbbcbcac";
    string s4 = "aadbbbaccc";

    Solution solution;
    cout << solution.isInterleave(s1, s2, s3) << endl;
    cout << solution.isInterleave(s1, s2, s4) << endl;

    return 0;
}

