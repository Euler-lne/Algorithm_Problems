// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=160 lang=cpp
 * @lcpr version=30204
 *
 * [160] 相交链表
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// @lcpr-template-end
// @lc code=start

//  * Definition for singly-linked list.

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, bool> map;
        for (ListNode *cur = headA; cur != nullptr; cur = cur->next)
            map[cur] = true;
        ListNode *HB = new ListNode(-1);
        HB->next = headB;
        for (ListNode *cur = HB; cur != nullptr; cur = cur->next) {
            if (map.find(cur->next) != map.end())
                return cur->next;
        }
        delete HB;
        return nullptr;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,9,1,2,4]\n[3,2,4]\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n[2,6,4]\n[1,5]\n3\n2\n
// @lcpr case=end

 */
