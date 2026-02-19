#include <cstdio>
#include <iostream>

const int MAX_N = 1e5 + 5;
int n, m;
long long arr[MAX_N] = {0};

void set(int l, int r, int value);
void swap(int &a, int &b);

int main()
{
    scanf("%d %d", &n, &m);
    int l, r;
    scanf("%d", &l);
    for (int i = 1; i < m; i++) {
        scanf("%d", &r);
        set(l, r, 1);
        l = r;
    }
    long long ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        arr[i] += arr[i - 1];
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        // a 直接付钱
        // b c 需要买一次卡C元，然后每次就是B元
        ans += std::min((c + b * arr[i]), (a * arr[i]));
    }
    printf("%lld", ans);
    return 0;
}

void set(int l, int r, int value)
{
    if (l > r)
        swap(l, r);
    arr[l] += value;
    arr[r] -= value;
}
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
