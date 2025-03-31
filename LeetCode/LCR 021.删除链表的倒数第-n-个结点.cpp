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
        ListNode *nodeArr[30];
        ListNode *cur = head, *pre = nullptr;
        int i = 0;
        while (cur != nullptr)
        {
            nodeArr[i] = cur;
            cur = cur->next;
            i++;
        }
        int len = i;
        i = len - n; // 这里的i代表需要删除的下标
        cur = nodeArr[i];
        if (i != 0)
        {
            pre = nodeArr[i - 1];
            pre->next = cur->next;
            return head;
        }
        else
        {
            return cur->next;
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
