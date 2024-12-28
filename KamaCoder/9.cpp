#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) % 2 == 0 ? (n % 10) : 0;
            n /= 10;
        }
        cout << sum << endl
             << endl;
    }
    return 0;
}
