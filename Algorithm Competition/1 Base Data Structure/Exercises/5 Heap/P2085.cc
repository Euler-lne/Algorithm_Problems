#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int function(vector<int> a, int x)
{
    return x * x * a[0] + x * a[1] + a[2];
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> parameter(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
        }
    }
}