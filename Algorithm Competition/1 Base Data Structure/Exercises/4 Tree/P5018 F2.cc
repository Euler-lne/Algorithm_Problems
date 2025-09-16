#include <iostream>

const int N = 1e6 + 10;
int n, v[N], l[N], r[N], son[N];
bool dfs(int x, int y)
{
    if (x == -1 && y == -1)
        return true; // 都是叶子节点时满足条件
    if (x == -1 || y == -1)
        return false; // 其中一个为叶子节点不满足
    if (v[x] != v[y])
        return false; // v值不同不满足
    return dfs(l[x], r[y]) && dfs(r[x], l[y]);
}
int count(int x)
{
    if (x == -1)
        return 0;
    son[x] = count(l[x]) + count(r[x]) + 1;
    return son[x];
}
int main()
{
    //	freopen(".in","r",stdin);
    //	freopen(".out","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &l[i], &r[i]);
    count(1); // 计算子树的节点个数
    int sum = 0;
    for (int i = 1; i <= n; i++)
        if (dfs(i, i))
            sum = sum > son[i] ? sum : son[i];
    printf("%d\n", sum);
    return 0;
}
