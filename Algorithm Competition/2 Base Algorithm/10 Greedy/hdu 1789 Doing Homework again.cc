#include <algorithm>
#include <cstdio>
#include <functional> // 必须包含，否则 greater 未定义
#include <queue>
#include <vector>

using namespace std;

struct Homework {
    int day, score;
};

bool cmp(const Homework &a, const Homework &b)
{
    if (a.day != b.day)
        return a.day < b.day;
    return a.score < b.score;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<Homework> arr(n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i].day);
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i].score);

        sort(arr.begin(), arr.end(), cmp);

        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            pq.push(arr[i].score);
            if ((int)pq.size() > arr[i].day) {
                ans += pq.top();
                pq.pop();
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}