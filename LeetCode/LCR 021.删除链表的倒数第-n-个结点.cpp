/*
 * @lc app=leetcode.cn id=LCR 021 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 021] 删除链表的倒数第 N 个结点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head, *slow = head;
        int i = 0;
        while (fast != nullptr)
        {
            fast = fast->next;
            if (i > n)
            {
                slow = slow->next;
            }
            i++;
        }
        if (n == i)
            return head->next;
        else
        {
            slow->next = slow->next->next;
            return head;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */
