// 需要知道的是 F(x) 也是一个单谷函数，一次函数也考虑在内
#include <cfloat>
#include <iostream>
const int N = 114514;
int a[N], b[N], c[N];
double eps = 1e-9;
// DBL_MIN 是正的最小数

using namespace std;

double F(int n, double x)
{
    double ans = -DBL_MAX;
    for (int i = 1; i <= n; i++) {
        double y = a[i] * x * x + b[i] * x + c[i];
        ans = max(ans, y);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }
        double l = 0, r = 1000;
        while (r - l >= eps) {
            double mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
            if (F(n, mid1) <= F(n, mid2))
                r = mid2;
            else
                l = mid1;
        }
        printf("%.4f\n", F(n, r));
    }
    return 0;
}