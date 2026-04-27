#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n;
    long long ans = 0;
    scanf("%d", &n);
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }
    sort(h.begin(), h.end());
    int i = 0, j = h.size() - 1;
    while (i < j) {
        ans += (h[j] - h[i]) * (h[j] - h[i]);
        i++;
        ans += (h[j] - h[i]) * (h[j] - h[i]);
        j--;
    }
    printf("%lld", ans);
    return 0;
}