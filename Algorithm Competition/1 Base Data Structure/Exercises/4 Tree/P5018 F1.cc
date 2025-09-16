#include <iostream>
#include <queue>

using namespace std;

typedef struct TreeNode {
    int val;
    int left;
    int right;
} TreeNode;

vector<TreeNode> tree;

int max_tree_node(int root)
{
    int ans = 1;
    int level = 1;
    if (tree[root].left == -1 || tree[root].right == -1)
        return 1;
    queue<int> left, right;
    left.push(tree[root].left);
    right.push(tree[root].right);
    while (!left.empty()) {
        int l = left.front();
        int r = right.front();

        left.pop();
        right.pop();
        if (l != -1 && r != -1) {
            if (tree[l].val != tree[r].val)
                return 1;
        } else {
            if (l != r) // 也就是两者都不为空
                return 1;
        }

        ans += (l != -1 ? 2 : 0);
        if (l != -1) {
            left.push(tree[l].left);
            left.push(tree[l].right);
            right.push(tree[r].right);
            right.push(tree[r].left);
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    tree.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> tree[i].val;
    }
    for (int i = 1; i <= n; i++) {
        cin >> tree[i].left;
        cin >> tree[i].right;
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, max_tree_node(i));
    }
    cout << ans;
    return 0;
}