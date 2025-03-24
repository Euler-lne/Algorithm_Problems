/*
 * @lc app=leetcode.cn id=面试题 02.02 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 02.02] 返回倒数第 k 个节点
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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int kthToLast(ListNode *head, int k)
    {
        int len = 0;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            len++;
            cur = cur->next;
        }
        cur = head;
        for (int i = 0; i < len - k; i++)
        {
            cur = cur->next;
        }
        return cur->val;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

 */
