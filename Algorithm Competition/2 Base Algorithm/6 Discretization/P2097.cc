#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]); // 路径压缩
    return parent[x];
}

void unite(int a, int b)
{
    int ra = find(a), rb = find(b);
    if (ra != rb)
        parent[ra] = rb; // 简单合并，未按秩优化也可通过本题
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    parent.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        parent[i] = i;

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        unite(a, b);
    }

    vector<bool> isRoot(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        isRoot[find(i)] = true;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (isRoot[i])
            ans++;
    }
    printf("%d\n", ans);

    return 0;
}