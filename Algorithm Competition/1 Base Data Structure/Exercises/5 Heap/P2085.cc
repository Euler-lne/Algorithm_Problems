#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int func(vector<int> param, int val)
{
    return val * val * param[0] + val * param[1] + param[2];
}

int main()
{
    // 大根堆反向输出
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    priority_queue<int> heap;
    vector<vector<int>> param(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            cin >> param[i][j];
    }
    for (int i = 0; i < n; i++) {
        heap.push(func(param[i], 1)); // 里面存放了 n个数
    }
    for (int i = 0; i < n; i++) {
        for (int j = 2; j <= m; j++) {
            int ans = func(param[i], j);
            if (heap.size() < m) {
                heap.push(ans); // 最先保证有 m 个数值
            } else {
                if (heap.top() > ans) {
                    heap.pop();
                    heap.push(ans);
                } else
                    break; // 后面只会越来越大
            }
        }
    }

    vector<int> ans(m, 0);
    for (int i = m - 1; i >= 0; i--) {
        ans[i] = heap.top();
        heap.pop();
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}