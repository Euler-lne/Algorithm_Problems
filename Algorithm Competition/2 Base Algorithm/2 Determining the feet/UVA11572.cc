#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t) {
        int n, ans = 0;
        cin >> n;
        vector<int> arr(n, 0);
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int l = 0, r = 0; r < n;) {
            if (!m[arr[r]]) {
                ans = max(ans, r - l + 1);
                m[arr[r++]]++;
            } else {
                while (arr[l] != arr[r] && l < r)
                    m[arr[l++]]--;
                m[arr[l++]]--;
            }
        }

        cout << ans << endl;
        t--;
    }
    return 0;
}