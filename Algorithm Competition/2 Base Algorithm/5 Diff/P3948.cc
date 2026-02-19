#include <iostream>

using namespace std;

int const MAX_N = 8 * 1e4 + 5;

long long arr[MAX_N] = {0}, suffix[MAX_N] = {0};
int n, max_value, min_value, mod;

void set(int l, int r, int x);
void build(int r);
void build();

int main()
{
    ios::sync_with_stdio(false);
    int opt;
    cin >> n >> opt >> mod >> min_value >> max_value;
    for (int i = 1; i <= opt; i++) {
        char c;
        cin >> c;
        if (c == 'A') {
            int l, r, x;
            cin >> l >> r >> x;
            set(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            build(r);
            cout << suffix[r] - suffix[l - 1] << endl;
        }
    }
    build();
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << suffix[r] - suffix[l - 1] << endl;
    }
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
        int value = arr[i] * i % mod;
        bool key = min_value <= value && value <= max_value;
        suffix[i] = suffix[i - 1] + (key ? 1 : 0);
    }
}

void build(int r)
{
    for (int i = 1; i <= r; i++) {
        arr[i] += arr[i - 1];
        int value = arr[i] * i % mod;
        bool key = min_value <= value && value <= max_value;
        suffix[i] = suffix[i - 1] + (key ? 1 : 0);
    }
    for (int i = r; i >= 1; i--)
        arr[i] -= arr[i - 1];
}