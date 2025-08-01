#include <iostream>
#include <math.h>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    vector<long long> prefix_sum(n + 1);
    vector<int> arr(n);
    long long max = -1, cur_sum = 0;
    prefix_sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> prefix_sum[i];
        arr[i - 1] = prefix_sum[i];
        prefix_sum[i] += prefix_sum[i - 1];
    }
    stack<int> s;
    // 当前值 cur
    // 左侧值 left
    // 右侧值 right
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            int cur = s.top();
            s.pop();
            int left = !s.empty() ? s.top() + 1 : 0; // 这里如果是空就是0
            cur_sum = (prefix_sum[i] - prefix_sum[left]) * arr[cur];
            if (max < cur_sum)
                max = cur_sum;
            // cout << "当前要被弹出的元素 " << arr[cur] << endl
            //      << "左侧：" << arr[left] << endl
            //      << "右侧：" << arr[i - 1] << endl;
        }
        s.push(i);
    }
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        int left = !s.empty() ? s.top() + 1 : 0;
        cur_sum = (prefix_sum[n] - prefix_sum[left]) * arr[cur];
        if (max < cur_sum)
            max = cur_sum;
        // cout << "当前要被弹出的元素 " << arr[cur] << endl
        //      << "左侧：" << arr[left] << endl
        //      << "右侧：" << arr[n - 1] << endl;
    }
    cout << max;
    return 0;
}