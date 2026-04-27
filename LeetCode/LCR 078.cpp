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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;
        for (auto list : lists) {
            if (list)
                pq.push(list);
        }
        if (pq.empty())
            return nullptr;
        ListNode *H = new ListNode();
        ListNode *cur = H;
        while (!pq.empty()) {
            cur->next = pq.top();
            cur = cur->next;
            pq.pop();
            if (cur->next)
                pq.push(cur->next);
        }
        cur = H->next;
        delete H;
        return cur;
    }

private:
    struct compare {
        bool operator()(ListNode *node1, ListNode *node2)
        {
            return node1->val > node2->val;
        }
    };
};
vector<ListNode *> Init(vector<vector<int>> arr)
{
    vector<ListNode *> lists(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        ListNode *H = new ListNode();
        ListNode *cur = H;
        for (int j = 0; j < arr[i].size(); j++) {
            ListNode *t = new ListNode(arr[i][j]);
            t->next = nullptr;
            cur->next = t;
            cur = cur->next;
        }
        cur = H->next;
        delete H;
        lists[i] = cur;
    }
    return lists;
}

int main()
{
    vector<vector<int>> arr{{1, 4, 5}, {1, 3, 4}, {2, 6}};
    Solution solution;
    vector<ListNode *> lists = Init(arr);
    ListNode *ans = solution.mergeKLists(lists);
    return 0;
}
