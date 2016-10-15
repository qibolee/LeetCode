#include "heads/head.h"
#include "heads/No99.h"

using namespace std;

int main() {

    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);

    Solution solution;
    solution.recoverTree(root);
    cout << root->left->val << " " << root->val << endl;

    return 0;
}

