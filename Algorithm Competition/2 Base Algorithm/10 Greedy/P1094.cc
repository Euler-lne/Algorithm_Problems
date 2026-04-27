#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int w, n;
    scanf("%d%d", &w, &n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = arr.size() - 1, j = 0; j <= i; i--) {
        if (arr[i] + arr[j] <= w)
            j++;
        ans++;
    }
    printf("%d", ans);
    return 0;
}