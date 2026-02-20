#include <cstring>
#include <iostream>
using namespace std;

int first[7]; // 记录每个余数最早出现的位置

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    memset(first, -1, sizeof(first)); // 全部设为 -1
    first[0] = 0;                     // 余数0第一次出现是位置0

    long long sum = 0;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum += x;
        int r = sum % 7;
        if (first[r] == -1) {
            first[r] = i; // 第一次出现
        } else {
            ans = max(ans, i - first[r]); // 出现多次，更新答案
        }
    }

    cout << ans << endl;
    return 0;
}