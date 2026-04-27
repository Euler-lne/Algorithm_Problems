#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int get_second_max(vector<int> arr)
{
    int n = arr.size();
    int m1 = max(arr[0], arr[1]), m2 = min(arr[0], arr[1]);
    for (int i = 2; i < n; i++) {
        if (arr[i] >= m1) {
            m2 = m1;
            m1 = arr[i];
        } else if (arr[i] > m2)
            m2 = arr[i];
    }
    return m2;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int t;
            scanf("%d", &t);
            arr[i][j] = arr[j][i] = t;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, get_second_max(arr[i]));
    }
    printf("1\n%d", ans);
    return 0;
}