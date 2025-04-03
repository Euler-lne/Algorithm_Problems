#include <iostream>
#include <deque>
#include <vector>
#include <math.h>
using namespace std;
const int INF = 0x7fffffff;
int main()
{
    int n, m, sum = 0, ans = -INF;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector<int> prefix_sum(n + 1);
    prefix_sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> prefix_sum[i];
        prefix_sum[i] += prefix_sum[i - 1];
    }
    deque<int> dq;
    dq.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        while (!dq.empty() && dq.front() + m < i)
            dq.pop_front();
        if (dq.empty())
            ans = max(ans, prefix_sum[i]);
        else
            ans = max(ans, prefix_sum[i] - prefix_sum[dq.front()]);
        while (!dq.empty() && prefix_sum[dq.back()] >= prefix_sum[i])
            dq.pop_back();
        dq.push_back(i);
    }
    cout << ans;
    return 0;
}