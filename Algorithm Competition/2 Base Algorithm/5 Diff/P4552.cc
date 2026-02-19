#include <iostream>

using namespace std;

int const MAX_N = 1e5 + 5;

long long arr[MAX_N] = {0};

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    long long p = 0, q = 0;
    for (int i = 2; i <= n; i++) {
        long long c = arr[i] - arr[i - 1];
        if (c > 0)
            p += c;
        else
            q -= c;
    }
    cout << max(p, q) << endl
         << abs(p - q) + 1;

    return 0;
}