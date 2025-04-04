#include <deque>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    vector<int> prefix_sum(n + 1);
    vector<int> arr(n + 2);
    prefix_sum[0] = 0;
    arr[0] = -1;
    arr[n + 1] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> prefix_sum[i];
        arr[i] = prefix_sum[i];
        prefix_sum[i] += prefix_sum[i - 1];
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        int start = i, end = i, sum = 0;
        while (start > 1 && arr[start - 1] >= arr[i])
            start--;
        while (end < n && arr[end + 1] >= arr[i])
            end++;
        if (start == end)
            ans = max(ans, arr[i] * arr[i]);
        else
            ans = max(ans, arr[i] * (prefix_sum[end] - prefix_sum[start - 1]));
    }
    cout << ans;
    return 0;
}