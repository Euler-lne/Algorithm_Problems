#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) { // 循环处理多组测试用例
        int p;
        scanf("%d", &p);
        vector<vector<long long>> arr(n + 2, vector<long long>(m + 2, 0));
        // 读入 p 个监控矩形，进行差分
        while (p--) {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            arr[x1][y1]++;
            arr[x1][y2 + 1]--;
            arr[x2 + 1][y1]--;
            arr[x2 + 1][y2 + 1]++;
        }
        // 第一次前缀和：得到每个位置被覆盖的次数
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        // 将覆盖次数 >1 的置为 1，并计算覆盖格子的二维前缀和
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                if (arr[i][j] > 1)
                    arr[i][j] = 1;
                arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            }
        int q;
        scanf("%d", &q);
        while (q--) {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            long long area = (long long)(x2 - x1 + 1) * (y2 - y1 + 1);
            long long covered = arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1];
            puts(covered == area ? "YES" : "NO");
        }
    }
    return 0;
}