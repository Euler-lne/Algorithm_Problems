#include <cstdio>

const int N = 5e6 + 1;

int a[N];

void swap(int &b, int &c)
{
    int t = b;
    b = c;
    c = t;
}

int quit_sort(int l, int r, int k)
{
    int mid = a[l + (r - l) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (a[i] < mid)
            i++;
        while (a[j] > mid)
            j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++, j--;
        }
    }
    // l - j
    if (l <= j && k <= j)
        return quit_sort(l, j, k);
    // i - r
    if (i <= r && k >= i)
        return quit_sort(i, r, k);
    return a[k];
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d", quit_sort(0, n - 1, k));
    return 0;
}
