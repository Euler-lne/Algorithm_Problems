#include <iostream>
#include <vector>
using namespace std;

int m, n;
const int MOD_NUM = 998244353;
vector<long long> arr;
void set(int l, int r, int x);
void build();

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        arr.resize(n + 2, 0);
        while (m--) {
            int l, r, x;
            cin >> l >> r >> x;
            set(l, r, x);
        }
        build();
    }
    return 0;
}

void set(int l, int r, int x)
{
    arr[l] += x;
    arr[r + 1] -= x;
}

void build()
{
    for (int i = 1; i <= n; i++) {
        arr[i] += arr[i - 1];
    }
}