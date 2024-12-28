#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str1, str2;
        vector<char> arr;
        cin >> str1 >> str2;
        for (int i = 0; i < str1.size() / 2; i++)
            arr.push_back(str1[i]);
        for (int i = 0; i < str2.size(); i++)
            arr.push_back(str2[i]);
        for (int i = str1.size() / 2; i < str1.size(); i++)
            arr.push_back(str1[i]);

        for (int i = 0; i < str1.size() + str2.size(); i++)
            cout << arr[i];
        cout << endl;
    }
    return 0;
}