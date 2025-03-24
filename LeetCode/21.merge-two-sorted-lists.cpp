// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=21 lang=cpp
 * @lcpr version=30204
 *
 * [21] 合并两个有序链表
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
// @lc code=start
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        ListNode *cur = list1->val < list2->val ? list1 : list2;
        ListNode *head = new ListNode, *pre;
        head->next = cur;
        pre = head;
        bool isChanged = false;
        while (IsContinue(list1, list2))
        {
            isChanged = false;
            while (IsContinue(list1, list2) && list1->val < list2->val)
            {
                list1 = list1->next;
                pre = pre->next;
                isChanged = true;
            }
            if (isChanged)
                pre->next = list2;
            isChanged = false;
            while (IsContinue(list1, list2) && list1->val >= list2->val)
            {
                list2 = list2->next;
                pre = pre->next;
                isChanged = true;
            }
            if (isChanged)
                pre->next = list1;
        }
        if (list1 == nullptr)
            pre->next = list2;
        else if (list2 == nullptr)
            pre->next = list1;
        pre = head->next;
        delete head;
        return pre;
    }

private:
    bool IsContinue(ListNode *list1, ListNode *list2)
    {
        return list1 != nullptr && list2 != nullptr;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,4]\n[1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[0]\n
// @lcpr case=end

 */
