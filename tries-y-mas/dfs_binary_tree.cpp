#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

void dfs(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    // Process the data of the current node
    cout << node->val << " ";

    // Recursively traverse the left subtree
    dfs(node->left);

    // Recursively traverse the right subtree
    dfs(node->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Perform DFS traversal
    dfs(root);
    cout << endl;

    return 0;
}
