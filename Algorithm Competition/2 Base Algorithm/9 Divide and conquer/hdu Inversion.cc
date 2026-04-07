#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e5 + 5;
int a[N], b[N];
long long cnt; // 逆序对可能超过 int 范围 (n最大1e5，最大逆序对数约5e9)

void merge(int l, int mid, int r)
{
    int i = l, j = mid + 1, t = 0;
    while (i <= mid && j <= r) {
        if (a[i] > a[j]) {
            b[t++] = a[j++];
            cnt += mid - i + 1; // 统计逆序对
        } else {
            b[t++] = a[i++];
        }
    }
    while (i <= mid)
        b[t++] = a[i++];
    while (j <= r)
        b[t++] = a[j++];
    for (int k = 0; k < t; k++) // 修正：k++ 而不是 t++
        a[l + k] = b[k];
}

void merge_sort(int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge(l, mid, r);
}

int main()
{
    int n, k;
    while (scanf("%d%d", &n, &k) == 2) {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]); // 加上 &
        cnt = 0;
        merge_sort(0, n - 1);
        long long ans = cnt - k;
        if (ans < 0)
            ans = 0;
        printf("%lld\n", ans);
    }
    return 0;
}