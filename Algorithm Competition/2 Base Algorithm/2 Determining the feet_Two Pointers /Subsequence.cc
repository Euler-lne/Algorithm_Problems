#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, s, ans;
        cin >> n >> s;
        vector<int> arr(n, 0);
        for (int j = 0; j < n; j++)
            cin >> arr[j];
        ans = n + 1;
        if (n == 1) {
            if (s > arr[0])
                cout << 0 << endl;
            else
                cout << 1 << endl;
            break;
        }
        int sum = arr[0] + arr[1];
        for (int j = 0, k = 1; k < n;) {
            if (sum >= s) {
                ans = ans > (k - j + 1) ? (k - j + 1) : ans;
                sum -= arr[j];
                j++;
                if (ans == 1) // 这个是最小的了，如果不退出j就会超过i
                    break;
            } else {
                k++;
                if (k < n)
                    sum += arr[k];
            }
        }
        cout << (ans == n + 1 ? 0 : ans) << endl;
    }
    return 0;
}