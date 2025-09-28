/*
 * @lc app=leetcode.cn id=61 lang=cpp
 * @lcpr version=30204
 *
 * [61] 旋转链表
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *H = new ListNode(0), *cur, *back;
        H->next = head;
        if (head == nullptr || k == 0)
            return head;
        int n = 0;
        cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }
        k %= n;
        if (k == 0)
            return head;
        cur = head, back = head;
        while (k) {
            cur = cur->next;
            k--;
        }
        while (cur->next) {
            cur = cur->next;
            back = back->next;
        }
        cur->next = H->next;
        cur = back->next;
        H->next = cur;
        back->next = nullptr;
        delete H;
        return cur;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2]\n4\n
// @lcpr case=end

 */
