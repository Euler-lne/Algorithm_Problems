#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> a;

bool check(int mid)
{
    // 错误在于混淆了分割点数量和段数的概念。
    // 分段问题的关键是：n个分割点将数组分成n+1段。
    int cur = 0, segments = 1; // 注意segments初始化为1 表示最开始有一段
    for (int i = 0; i < n; i++) {
        if (cur + a[i] > mid) // 这一段的值已经大于答案了 等价于添加分割点
        {
            cur = 0;    // 重制
            segments++; // 增加段数
            if (segments > m)
                return false;
        }
        cur += a[i];
    }
    return segments <= m;
    // 如果分割段数小于 输入的说明这个分割是正确的 不越界
    // 这个答案合理 并且可能存在更小的
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
        l = max(l, t);
        r += t;
    }
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid; // mid 可以是答案 但是还可能有更小的
        } else
            l = mid + 1;
    }
    cout << l;
    return 0;
}