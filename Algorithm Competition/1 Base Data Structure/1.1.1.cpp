#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
int main()
{
    int n, m;
    cin >> n >> m;
    Node *pre, *cur, *head;
    pre = new Node;
    pre->data = 1;
    pre->next = nullptr;
    head = pre;
    cur = nullptr;
    for (int i = 1; i < n; i++)
    {
        cur = new Node;
        cur->data = i + 1;
        cur->next = nullptr;
        pre->next = cur;
        pre = cur;
    }
    cur = head;
    pre->next = cur;
    while (cur->next != cur)
    {
        for (int i = 1; i < m; i++)
        {
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = cur->next;
        cout << cur->data << " ";
        delete cur;
        cur = pre->next;
    }
    cout << cur->data;
    return 0;
}