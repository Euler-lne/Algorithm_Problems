#include <deque>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    vector<int> prefix_sum(n + 1);
    vector<int> arr(n + 1);
    prefix_sum[0] = 0;
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> prefix_sum[i];
        arr[i] = prefix_sum[i];
        prefix_sum[i] += prefix_sum[i - 1];
    }
    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        }
    return 0;
}