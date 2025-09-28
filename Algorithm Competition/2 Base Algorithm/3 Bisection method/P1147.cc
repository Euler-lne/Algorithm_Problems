#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, sum = 3;
    cin >> n;
    for (int i = 1, j = 2; i <= n / 2;) {
        // 注意是 i<=n/2
        // i <= n / 2 更合理，因为序列起始点不可能超过n/2
        if (sum < n)
            sum += ++j;
        else if (sum > n)
            sum -= i++;
        else {
            cout << i << " " << j << endl;
            sum -= i++;
        }
    }
    return 0;
}