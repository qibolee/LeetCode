#include "heads/head.h"
#include "heads/No108.h"

using namespace std;

int main() {

    vector<int> vec = {1, 2, 3};

    Solution solution;
    auto root = solution.sortedArrayToBST(vec);
    cout << root->left->val << " " << root->val << " " << root->right->val << endl;

    return 0;
}

