// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=86 lang=cpp
 * @lcpr version=30204
 *
 * [86] 分隔链表
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
/**
 * Definition for singly-linked list.
 */
struct ListNode {
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
    ListNode *partition(ListNode *head, int x)
    {
        if (!head || !head->next)
            return head;
        ListNode *H = new ListNode(), *cur, *front;
        H->next = head;
        cur = H;
        front = H;
        while (cur && cur->next) {
            if (cur->next->val < x) {
                if (cur != front) {
                    ListNode *t = front->next;
                    front->next = cur->next;
                    cur->next = cur->next->next;
                    front->next->next = t;
                } else
                    cur = cur->next;
                front = front->next;
            } else
                cur = cur->next;
        }
        cur = H->next;
        delete H;
        return cur;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,4,3,2,5,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,4,3,0,2,5,2]\n3\n
// @lcpr case=end

 */
