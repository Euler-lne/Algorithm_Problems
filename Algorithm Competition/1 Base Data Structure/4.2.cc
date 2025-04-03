// 动态规划
// dp[i] = max(dp[i-1] + a[i], a[i])  dp[0] = a[0]
// dp[i] 表示以a[i] 结尾的 最大子序列和
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t, *dp;
        cin >> t;
        dp = new int[t];
        for (int j = 0; j < t; j++)
            cin >> dp[j];
        int start = 1, end = 1, p = 1, maxsum = dp[0];
        for (int j = 1; j < t; j++)
        {
            if (dp[j] <= dp[j - 1] + dp[j])
                dp[j] = dp[j - 1] + dp[j];
            else
                p = j + 1; // dp[j] 更大
            if (maxsum < dp[j])
            {
                start = p;
                end = j + 1;
                maxsum = dp[j];
            }
        }
        delete[] dp;
        cout << "Case " << i + 1 << ":" << endl;
        cout << maxsum << " " << start << " " << end << endl;
        if (i != n - 1)
            cout << endl;
    }
}