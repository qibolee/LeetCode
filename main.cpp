#include "heads/head.h"
#include "heads/No124.h"

using namespace std;

int main() {

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(3);
    Solution solution;
    cout << solution.maxPathSum(root) << endl;

    return 0;
}

