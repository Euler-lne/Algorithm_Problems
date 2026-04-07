#include <algorithm>
#include <cstdio>
using namespace std;

/*
分治思路
将数组分成左半和右半，最大子段和可能出现在：

完全在左半部分

完全在右半部分

跨越中点（左半的某后缀 + 右半的某前缀）
* */

int main()
{
    int n;
    scanf("%d", &n);
    long long ans = -1e18, cur = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        // cur 是上一次的最优子结构
        cur = max((long long)x, cur + x); // 当前子段和：要么从x开始，要么继续累加
        ans = max(ans, cur);
    }
    printf("%lld\n", ans);
    return 0;
}