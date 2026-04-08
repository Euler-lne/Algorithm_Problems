#include <iostream>
using namespace std;

void f(int x)
{
    for (int i = 14; i >= 0; --i) {
        if ((1 << i) <= x) { // 2^i <= x
            if (i == 0)
                cout << "2(0)";
            else if (i == 1)
                cout << "2";
            else {
                cout << "2(";
                f(i);
                cout << ")";
            }
            x -= (1 << i);
            if (x != 0)
                cout << "+";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    f(n);
    return 0;
}