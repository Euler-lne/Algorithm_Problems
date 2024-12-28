#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            string s;
            char t;
            cin >> s;
            for (int j = 0, k = 1; k < s.size(); k += 2, j += 2)
            {
                t = s[j];
                s[j] = s[k];
                s[k] = t;
            }
            cout << s << endl;
        }
    }
    return 0;
}