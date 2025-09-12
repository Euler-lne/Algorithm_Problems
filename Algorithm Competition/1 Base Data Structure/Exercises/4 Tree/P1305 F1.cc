#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

typedef struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

void preorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val;
    preorder(root->left);
    preorder(root->right);
}

void delete_tree(TreeNode *root)
{
    if (root->left != nullptr) {
        delete_tree(root->left);
        root->left = nullptr;
    }
    if (root->right != nullptr) {
        delete_tree(root->right);
        root->right = nullptr;
    }
    if (root->left == nullptr && root->right == nullptr) {
        delete root;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    TreeNode *root = new TreeNode;
    unordered_map<char, TreeNode *> map;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        TreeNode *node = map.find(s[0]) != map.end() ? map[s[0]] : root;
        node->val = s[0];
        if (s[1] != '*') {
            TreeNode *left = new TreeNode;
            left->val = s[1];
            node->left = left;
            map.insert(pair<char, TreeNode *>(s[1], left));
        } else {
            node->left = nullptr;
        }
        if (s[2] != '*') {
            TreeNode *right = new TreeNode;
            right->val = s[2];
            node->right = right;
            map.insert(pair<char, TreeNode *>(s[2], right));
        } else {
            node->right = nullptr;
        }
    }
    preorder(root);
    delete_tree(root);
    return 0;
}