/*
 * @lc app=leetcode.cn id=337 lang=cpp
 * @lcpr version=21914
 *
 * [337] 打家劫舍 III
 */
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    /*
    主要的解决方法：每个节点有两种状态：选中或者没有选中。
        f 选中的情况下：该节点的最大值为，该节点的值，加上该节点的孩子节点的
            没有选中的情况。
        g 未选中的情况下：为孩子节点每个中选中和没有选中的最大值之和
    采用后序遍历的方法，我们可以用哈希表来存f和g函数的值。
    */
    unordered_map<TreeNode *, int> f, g;
    void dfs(TreeNode *node)
    {
        if (!node)
            return;
        dfs(node->left);
        dfs(node->right);
        f[node] = node->val + g[node->left] + g[node->right];
        g[node] = max(f[node->left], g[node->left]) + max(f[node->right], g[node->right]);
    }

    int rob(TreeNode *root)
    {
        dfs(root);
        return max(f[root], g[root]);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,3,null,3,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,3,null,1]\n
// @lcpr case=end

 */
