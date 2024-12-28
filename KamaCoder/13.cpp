#include <iostream>
using namespace std;
int main()
{
    char c;
    int n;
    while (cin >> c >> n)
    {
        if (c == '@')
            break;
        // 第一行
        for (int i = 0; i < n - 1; i++)
            cout << " ";
        cout << c << endl;
        if (n == 1)
        {
            cout << endl;
            continue;
        }
        // 2～n-1行
        for (int i = 2; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
                cout << " ";
            cout << c;
            for (int j = 0; j < 2 * (i - 1) - 1; j++)
                cout << " ";
            cout << c << endl;
        }
        // 第n行
        for (int i = 0; i < 2 * n - 1; i++)
            cout << c;
        cout << endl
             << endl;
    }
    return 0;
}