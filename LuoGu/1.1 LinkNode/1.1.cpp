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
    Node *head = new (Node);
    head->next = nullptr;
    Node *pre, *cur;
    pre = head;
    cur = nullptr;
    for (int i = 0; i < n; i++)
    {
        cur = new (Node);
        cur->data = i + 1;
        pre->next = cur;
        pre = cur;
    }
    cur->next = head->next;
    cur = head;

    return 0;
}