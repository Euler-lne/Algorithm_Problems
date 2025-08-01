#include <deque>
#include <iostream>
using namespace std;
int n, l, r;
int a[200010];
int main()
{
    long long sum = 0;
    ios::sync_with_stdio(false);
    cin >> n >> l >> r;
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    int cur = 0, ll = cur + l, rr = cur + r;
    deque<int> dq;

    cout << sum;
    return 0;
}