// 贪心算法
// 加到一个正数，子序列和会增加；加到一个负数子序列和会减小
// 如果当前子序列和变为负数，那么这个负数会在接下来的累加中减少后面的求和
#include <iostream>
using namespace std;
const int INF = 0x7fffffff;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // p 代表当前的sum开始的下标
        int t, start = 1, end = 1, p = 1, maxsum = -INF, sum = 0;
        cin >> t;
        for (int j = 1; j <= t; j++)
        {
            int a;
            cin >> a;
            sum += a;
            if (sum > maxsum)
            {
                start = p;
                maxsum = sum;
                end = j;
            }
            if (sum < 0)
            {
                sum = 0;
                p = j + 1;
            }
        }
        cout << "Case " << i + 1 << ":" << endl;
        cout << maxsum << " " << start << " " << end << endl;
        if (i != n - 1)
            cout << endl;
    }
    return 0;
}