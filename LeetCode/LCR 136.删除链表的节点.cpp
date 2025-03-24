/*
 * @lc app=leetcode.cn id=LCR 136 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 136] 删除链表的节点
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
    ListNode *deleteNode(ListNode *head, int val)
    {
        ListNode *H = new ListNode, *pre, *cur;
        H->next = head;
        pre = H, cur = head;
        while (cur != nullptr)
        {
            if (cur->val == val)
            {
                pre->next = cur->next;
                cur = cur->next;
            }
            else
            {
                cur = cur->next;
                pre = pre->next;
            }
        }
        head = H->next;
        delete H;
        return head;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,5,1,9]\n5\n
// @lcpr case=end

// @lcpr case=start
// [4,5,1,9]\n1\n
// @lcpr case=end

 */
