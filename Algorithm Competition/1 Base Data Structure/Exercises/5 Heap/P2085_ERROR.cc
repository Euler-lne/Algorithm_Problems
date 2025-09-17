#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int func(vector<int> a, int x)
{
    return x * x * a[0] + x * a[1] + a[2];
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m, max_val = -1;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    vector<vector<int>> parameter(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> parameter[i][j];
        }
        for (int j = 1; j <= m; j++) {
            int ans = func(parameter[i], j);
            if (min_heap.size() < m) {
                min_heap.push(ans);
                max_heap.push(ans);
            } else {
                if (ans < max_heap.top()) {
                    max_heap.pop();
                    max_heap.push(ans);
                    min_heap.push(ans);
                }
            }
        }
        // FIXME:内存大小超出限制，一个堆暴力
        // FIXME:两个堆，大根限制存储范围，超时
    }
    for (int i = 0; i < m; i++) {
        cout << min_heap.top();
        min_heap.pop();
        if (i != m - 1)
            cout << " ";
    }
    return 0;
}