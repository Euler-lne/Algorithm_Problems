#include <iostream>
#include <map>
using namespace std;

const int N = 1e5 + 2;
int n, q, a[N], bucket[N], value[N];
int stmax[N][20], LOG2[N];
unordered_map<int, int> bucket_map;

void init();

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init();
    while (q--) {
        int l, r;
        cin >> l >> r;
        int l_key = bucket_map[l], r_key = bucket_map[r];
        int l_count = 1, r_count = 1;
        for (int i = l; a[i] == a[i + l_count] && i + l_count <= n; l_count++) {
        }
        for (int i = r; a[i] == a[i - r_count] && i - r_count >= 0; r_count++) {
        }

        int end = l + l_count, start = r - r_count;
        if (start < 0) { // 全部数一样
            cout << a[1] << endl;
        } else if (start > end) { // 只有两种数字
            count << l_count > r_count ? a[l] : a[r] << endl;
        } else {
            int max1 = max(l_count, r_count);
            int val1 = l_count > r_count ? a[l] : a[r];
            start = bucket_map[start], end = bucket_map[end];
        }
    }
    return 0;
}

void init()
{
    for (int i = 1, j = 0; i <= n; j++) {
        int count = 0;
        while (i + count <= n && a[i] == a[i + count])
            count++;
        bucket[j] = count;
        value[j] = a[i];
        bucket_map.insert(a[i], j);
        bucket[0] = j;
        i += count;
    }
    LOG2[0] = -1;
    for (int i = 1; i <= n; i++)
        LOG2[i] = LOG2[i >> 1] + 1;

    for (int i = 0; i <= bucket[0]; i++) {
        stmax[i][0] = bucket[i];
    }
    for (int j = 1; j <= LOG2[bucket[0]]; j++) {
        for (int i = 0; i <= bucket[0]; i++) {
            if (i + (1 << (j - 1)) <= bucket[0])
                stmax = max(stmax[i][j - 1], stmax[i + (1 << (j - 1))][j - 1]);
        }
    }
}