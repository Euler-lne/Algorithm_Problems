#include <iostream>
using namespace std;
int main()
{
    string s;
    int n, offset = 'a' - 'A';
    cin >> n;
    cin.get(); // 去掉换行符
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] != ' ')
            {
                if (s[j] >= 'Z')
                    s[j] -= offset;
                cout << s[j];
                while (j < s.size() && s[j] != ' ')
                    j++;
            }
        }
        cout << endl;
    }
    return 0;
}