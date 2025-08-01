#include <iostream>
#include <stack>
#include <string>
#define ISOP(c) (c == '*' || c == '+')
#define ISUPPER(tc, ic) (tc == '*' && ic == '+') // 栈顶与入栈比较
using namespace std;
stack<int> num_s;
string str;
void caculate(char op);
int get_num(int s, int e);
// 栈顶优先级高于要入栈元素就出栈，出栈的时候可以计算
int main()
{
    ios::sync_with_stdio(false);
    stack<char> op_s;
    cin >> str;
    for (int i = 0; i < str.size();) {
        if (ISOP(str[i])) {
            while (!op_s.empty() && ISUPPER(op_s.top(), str[i])) {
                // 注意这里是while！！！
                caculate(op_s.top());
                op_s.pop();
            }
            op_s.push(str[i]);
            i++;
        } else {
            int j = i;
            while (j < str.size() && !ISOP(str[j]))
                j++;
            num_s.push(get_num(i, j));
            i = j;
        }
    }
    while (!op_s.empty()) {
        caculate(op_s.top());
        op_s.pop();
    }
    cout << num_s.top();
    return 0;
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
    else
        answer = s1 + s2;
    answer %= 10000;
    num_s.push(answer);
}
int get_num(int s, int e)
{
    int num = 0, times = 1;
    for (int i = e - 1; i >= s; i--) {
        num += (str[i] - '0') * times;
        times *= 10;
    }
    num %= 10000;
    return num;
}