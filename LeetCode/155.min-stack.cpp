/*
 * @lc app=leetcode.cn id=155 lang=cpp
 * @lcpr version=30204
 *
 * [155] 最小栈
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
class MinStack
{
public:
    MinStack()
    {
        stk.clear();
        min.clear();
    }

    void push(int val)
    {
        int id = min.size() - 1;
        if (min.size() == 0)
            min.push_back(val);
        else
            min.push_back(min[id] < val ? min[id] : val);
        stk.push_back(val);
    }

    void pop()
    {
        stk.pop_back();
        min.pop_back();
    }

    int top()
    {
        return stk[stk.size() - 1];
    }

    int getMin()
    {
        return min[min.size() - 1];
    }

private:
    vector<int> stk;
    vector<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

/*
// @lcpr case=start
// ["MinStack","push","push","push","getMin","pop","top","getMin"][[],[-2],[0],[-3],[],[],[],[]]\n
// @lcpr case=end

 */
