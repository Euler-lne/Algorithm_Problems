#include <cstdio>

const int MAX_N = 5e5 + 5;

int a[MAX_N], b[MAX_N];
long long cnt;

void merge(int l, int mid, int r)
{
    int i = l, j = mid + 1, t = 0;
    while (i <= mid && j <= r) {
        if (a[i] > a[j]) {
            b[t++] = a[j++];
            cnt += (mid - i + 1);
        } else
            b[t++] = a[i++];
    }
    while (i <= mid)
        b[t++] = a[i++];
    while (j <= r)
        b[t++] = a[j++];
    for (i = 0; i < t; i++)
        a[l + i] = b[i];
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
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    merge_sort(0, n - 1);
    printf("%d", cnt);
    return 0;
}