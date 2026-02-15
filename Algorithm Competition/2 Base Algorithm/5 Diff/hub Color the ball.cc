#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 3;
vector<int> arr(N, 0);

void set(int l, int r);
void reset(int n);

int main()
{
    int n;
    cin >> n;
    while (n) {
        for (int i = 1; i <= n; i++) {
            int l, r;
            cin >> l >> r;
            set(l, r);
        }
        for (int i = 1; i <= n; i++) {
            arr[i] += arr[i - 1];
            cout << arr[i] << " ";
        }
        cout << endl;
        reset(n);
        cin >> n;
    }
}
void set(int l, int r)
{
    arr[l] += 1;
    arr[r + 1] -= 1;
}

void reset(int n)
{
    for (int i = 0; i <= n; i++)
        arr[i] = 0;
}