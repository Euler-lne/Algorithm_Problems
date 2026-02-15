#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<long long> arr(n + 5, 0);
    while (m--) {
        long long l, r, s, e, d;
        cin >> l >> r >> s >> e;
        d = (e - s) / (r - l);
        arr[l] += s;
        arr[l + 1] += d - s;
        arr[r + 1] -= (d + e);
        arr[r + 2] += e;
    }
    for (int i = 1; i <= n; i++) {
        arr[i] += arr[i - 1];
    }
    long long max_value = -1, xor_value;
    for (int i = 1; i <= n; i++) {
        arr[i] += arr[i - 1];
        if (max_value < arr[i])
            max_value = arr[i];
        xor_value = i == 1 ? arr[i] : xor_value ^ arr[i];
    }
    cout << xor_value << " " << max_value;
    return 0;
}