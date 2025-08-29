// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=143 lang=cpp
 * @lcpr version=30204
 *
 * [143] 重排链表
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 */

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        stack<ListNode *> stk;
        ListNode *cur = head->next;
        int len = 1;
        while (cur) {
            stk.push(cur);
            cur = cur->next;
            len++;
        }
        cur = head;
        ListNode *next = head->next;
        // 需要出栈元素为 (len - 1) / 2;
        for (int i = 0; i < (len - 1) / 2; i++) {

            cur->next = stk.top();
            stk.pop();
            cur = cur->next; // 反插

            cur->next = next; // 正插入

            next = next->next;
            cur = cur->next;
        }
        if ((len - 1) % 2)
            cur = cur->next;
        cur->next = nullptr;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */
