#include <iostream>
#include <vector>

using namespace std;

double eps = 1e-6;
vector<double> param;
int n;

double caculate(double x)
{
    double ans = 0;
    for (auto e : param)
        ans = ans * x + e; // 秦九韶
    return ans;
}

int main()
{
    double l, r, mid;
    cin >> n >> l >> r;
    param.resize(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> param[i];
    while (r - l >= eps) {
        mid = l + (r - l) / 2;
        if (caculate(mid - eps) > caculate(mid))
            r = mid;
        else
            l = mid;
    }
    printf("%.5f", mid);
    return 0;
}