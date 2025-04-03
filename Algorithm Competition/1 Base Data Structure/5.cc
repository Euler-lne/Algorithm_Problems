// hdu 1062
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
        stack<char> s;
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == ' ')
            {
                while (!s.empty())
                {
                    cout << s.top();
                    s.pop();
                }
                cout << " ";
            }
            else
                s.push(str[j]);
        }
        while (!s.empty())
        {
            cout << s.top();
            s.pop();
        }
        cout << endl;
    }
    return 0;
}