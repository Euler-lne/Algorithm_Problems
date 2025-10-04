#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
实数二分


一个数组的平均值一定位于数组[最小值，最大值]的区间内，
且数组中任意一段连续的序列的平均值都不会超过这个区间。
知道了这一点后，我们再来看题目要求输出的段落的平均值（ 等于 段落总价值 除以 段落长度），
是不是也一定位于数组[最小值，最大值]的区间内呢。
由此，我们便找到了关键的二分法的区间，即[最小值，最大值]，
段落的最大平均值一定位于这个区间内。

sum[i]=sum[i-1]+a[i]-mid;

这是前缀和的计算公式，为什么要减去一个mid呢？
mid作为当前被假设的段落平均值的最大值，
——>这时候又涉及到了一个知识，当一个数组中的每个元素，都减去他的平均值后求和，
得到的结果一定大于或者等于0。
前缀和的计算公式就是基于这样的原理：
    1.sum[i]-sum[q.front()]>=0时，说明mid值刚好或者过小，需要再向右区间寻找。
    2.sum[i]-sum[q.front()]<0时，说明mid值过大，需要再向左区间寻找。

单调队列的使用
单调队列维护了一个长度区间在[S,T]内的段落价值和的单调性，在编写单调队列的代码时，
我们要确定好两点：
    1.单调队列的单调性：单调队列到底是单增还是单减呢？
    以本题为例——>本题要求找平均值最大的段落，通过前缀和如何表示平均值最大的段落呢？
    那么就是当前1~i 的前缀和，减去1~i-T 或者 1~i-S 的前缀和以后的最大情况，
    显然1~i 的前缀和在当前情况下是一定的，那么1~i-T 或者1~i-S 的前缀和哪一个最小，
    1~i 的前缀和减去它的值就最大——>由此我们分析得出了，单调队列的单调性应该是单调递增的。

    2.单调队列维护的区间范围控制，单调队列维护的区间应该在[S,T]之间，
    所以我们应该判断，当 q.front()<i-T时，表明队列头存储的前缀和已经超出了现区间范围，
    应该丢弃。

    3. 单调递增保证了在区间[i-s或者i-t , i]中对首元素为最小值，队尾元素为最大值，
    需要找到最小值，所以采用单调递增
*/

int n, s, t;
vector<int> a;
const int INT_MAX_ = 0x7fffffff;
const int INT_MIN_ = -INT_MAX_;

bool check(double mid)
{
    vector<double> sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i - 1] - mid;
    deque<int> q;
    for (int i = 1; i <= n; i++) {
        if (i - s >= 0) { // i-s 是最短要求的长度, i代表末尾位置
            while (!q.empty() && sum[i - s] < sum[q.back()])
                q.pop_back();
            q.push_back(i - s);
        }
        if (!q.empty() && q.front() < i - t) // i-t 是允许的最长的
            q.pop_front();
        if (!q.empty() && sum[i] - sum[q.front()] >= 0)
            return true;
        // 每次都检测当前值减去最小值，如果大于0就说明：
        //      区间内的平均值大于当前预测平均值，这样预测平均值可以增大
    }
    return false;
}

int main()
{
    int max_val = INT_MIN_, min_val = INT_MAX_;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        max_val = max(t, max_val);
        min_val = min(t, min_val);
        a.push_back(t);
    }
    double l = min_val, r = max_val, mid;
    while (r - l > 1e-4) {
        mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.3f", l);
    return 0;
}