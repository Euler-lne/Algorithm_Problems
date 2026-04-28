#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        int item;
        scanf("%d", &item);
        pq.push(item);
    }
    int ans = 0;
    while (pq.size() > 1) {
        int t1 = pq.top();
        pq.pop();
        int t2 = pq.top();
        pq.pop();
        ans += (t1 + t2);
        pq.push(t1 + t2);
    }
    printf("%d", ans);
    return 0;
}