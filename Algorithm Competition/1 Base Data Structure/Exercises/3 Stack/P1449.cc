#include <iostream>
#include <stack>
#include <string>
#define ISOP(c) (c == '*' || c == '/' || c == '+' || c == '-')

using namespace std;
string str;
stack<int> num_s;
int get_type_of_str(int s, int e);
int get_num(int s, int e);
void caculate(char op);
int main()
{
    ios::sync_with_stdio(false);
    cin >> str;
    int start, end = -1;
    while (end == -1 || str[end] != '@') {
        start = end + 1;
        end = start;
        while (str[end] != '.' && str[end] != '@')
            end++;
        // 这个区间里面可能 只有数字，只有符号，都有
        int type = get_type_of_str(start, end);
        if (type == 0)
            num_s.push(get_num(start, end));
        else if (type == 1)
            caculate(str[start]);
        else {
            while (start != end) {
                if (ISOP(str[start])) {
                    caculate(str[start]);
                    start++;
                } else {
                    num_s.push(get_num(start, end));
                    start = end;
                }
            }
        }
    }
    cout << num_s.top();
    return 0;
}
/// @brief 判断符号类型
/// @param s 开始下标
/// @param e 结束下标
/// @return 0:数字 1:符号 2:混合
int get_type_of_str(int s, int e)
{
    if (s - e == 1) // 长度为1
    {
        return ISOP(str[s]) ? 1 : 0;
    } else {
        char c1 = str[s], c2 = str[e - 1];
        if (ISOP(c1) && ISOP(c2))
            return 1;
        else if (!ISOP(c1) && !ISOP(c2))
            return 0;
        else
            return 2;
    }
}

int get_num(int s, int e)
{
    int num = 0, times = 1;
    for (int i = e - 1; i >= s; i--) {
        num += (str[i] - '0') * times;
        times *= 10;
    }
    return num;
}

void caculate(char op)
{
    int s1, s2, answer;
    s2 = num_s.top();
    num_s.pop();
    s1 = num_s.top();
    num_s.pop();
    if (op == '*')
        answer = s1 * s2;
    else if (op == '/')
        answer = s1 / s2;
    else if (op == '+')
        answer = s1 + s2;
    else
        answer = s1 - s2;
    num_s.push(answer);
}
