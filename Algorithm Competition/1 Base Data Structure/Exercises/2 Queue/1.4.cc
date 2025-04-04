#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, ans = 0;
    deque<int> dq;
    cin >> n;
    vector<int> prefix_sum(2 * n);
    vector<int> a(n + 1);
    a[0] = 0;
    prefix_sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix_sum[i] = a[i] + prefix_sum[i - 1];
    }
    for (int i = n + 1; i < 2 * n; i++)
        prefix_sum[i] = a[i - n] + prefix_sum[i - 1];
    for (int i = 1; i < 2 * n; i++)
    {
        while (!dq.empty() && dq.front() + n <= i)
            dq.pop_front();
        while (!dq.empty() && prefix_sum[i] < prefix_sum[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        if (i >= n && prefix_sum[dq.front()] - prefix_sum[i - n] >= 0)
            ans++;
    }
    cout << ans;
    return 0;
}