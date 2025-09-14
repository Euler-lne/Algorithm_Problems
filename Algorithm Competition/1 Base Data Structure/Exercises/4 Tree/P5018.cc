#include <iostream>
#include <queue>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

int max_tree_node(TreeNode *root)
{
    int ans = 0;
    int level = 1;
    if (root->left == nullptr || root->right == nullptr)
        return 1;
    queue<TreeNode *> left, right;
}

int main()
{
    return 0;
}