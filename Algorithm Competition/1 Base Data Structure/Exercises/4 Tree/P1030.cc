#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
string post;
unordered_map<char, int> in_map;
int post_idx = 0;
typedef struct TreeNode {
    TreeNode *left, *right;
    char val;
} TreeNode;

TreeNode *create_tree(int left, int right)
{
    if (left > right || post_idx < 0)
        return nullptr;
    char val = post[post_idx];
    TreeNode *node = new TreeNode;
    node->val = val;
    post_idx--;
    node->right = create_tree(in_map[val] + 1, right);
    node->left = create_tree(left, in_map[val] - 1);
    return node;
}

void preoder(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val;
    preoder(root->left);
    preoder(root->right);
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
    TreeNode *root;
    string in;
    cin >> in >> post;
    for (int i = 0; i < in.length(); i++) {
        in_map.insert(pair<char, int>(in[i], i));
    }
    post_idx = in.length() - 1;
    root = create_tree(0, in.length() - 1);
    preoder(root);
    delete_tree(root);
    return 0;
}
