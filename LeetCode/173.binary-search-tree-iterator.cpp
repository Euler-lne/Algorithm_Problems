/*
 * @lc app=leetcode.cn id=173 lang=cpp
 * @lcpr version=30204
 *
 * [173] 二叉搜索树迭代器
 */

// @lcpr-template-start
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
// @lcpr-template-end
struct TreeNode {
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
 */
class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
    {
        TreeNode *cur = root;
        while (cur) {
            stk.push(cur);
            cur = cur->left;
        }
    }

    int next()
    {
        TreeNode *cur = stk.top();
        int val = cur->val;
        stk.pop();
        if (cur->right) {
            cur = cur->right;
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
        }
        return val;
    }

    bool hasNext()
    {
        return !stk.empty();
    }

private:
    stack<TreeNode *> stk; // 中序列
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

/*
// @lcpr case=start
// ["BSTIterator","next","next","hasNext","next","hasNext","next","hasNext","next","hasNext"] '+' [[[7,3,15,null,null,9,20]],[],[],[],[],[],[],[],[],[]]\n
// @lcpr case=end



 */
