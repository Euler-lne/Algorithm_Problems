#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int sum = 3;
    for (int i = 1, j = 2; i <= n / 2;) {
        if (n == sum) {
            cout << i << " " << j << endl;
            sum -= i; // 先累减i，然后再加i
            i++;
        } else if (n < sum) {
            sum -= i;
            i++;
        } else {
            j++; // 注意这里的顺序，要先累加j然后再累加sum
            sum += j;
        }
    }
    return 0;
}