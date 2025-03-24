#include <iostream>
using namespace std;
typedef struct NodeList
{
    int next, pre;
} NodeList;
void InitNodeList(NodeList *nodeLise, int n);
void PrintNodeList(NodeList *nodeList, int n);
void RemoveNodeList(NodeList *nodeList, int m);
int main()
{
    int n, m;
    cin >> n;
    NodeList *nodeList = new NodeList[n]; // 动态分配数组
    nodeList[0].next = -1;
    nodeList[0].pre = -1;
    InitNodeList(nodeList, n);
    // PrintNodeList(nodeList, n);
    cin >> m;
    RemoveNodeList(nodeList, m);
    PrintNodeList(nodeList, n);
    delete[] nodeList;
    return 0;
}

void InitNodeList(NodeList *nodeList, int n)
{
    for (int i = 1; i < n; i++)
    {
        int x, isRight, temp;
        cin >> x >> isRight;
        if (isRight == 1)
        {
            temp = nodeList[x - 1].next;
            nodeList[x - 1].next = i;
            nodeList[i].next = temp;
            nodeList[i].pre = x - 1;
            if (temp != -1)
                nodeList[temp].pre = i;
        }
        else
        {
            temp = nodeList[x - 1].pre;
            nodeList[x - 1].pre = i;
            nodeList[i].next = x - 1;
            nodeList[i].pre = temp;
            if (temp != -1)
                nodeList[temp].next = i;
        }
    }
}

void PrintNodeList(NodeList *nodeList, int n)
{
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "x:" << i + 1
    //          << " next: " << nodeList[i].next
    //          << " pre: " << nodeList[i].pre << endl;
    // }
    int head = -1;
    for (int i = 0; i < n; i++)
    {
        if (nodeList[i].pre == -1)
        {
            head = i;
        }
    }
    if (head == -1)
        cout << "";
    else
    {
        int cur = head;
        while (cur != -1)
        {
            cout << cur + 1 << " ";
            cur = nodeList[cur].next;
        }
    }
    return;
}

void RemoveNodeList(NodeList *nodeList, int m)
{
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        x--;
        int pre = nodeList[x].pre, next = nodeList[x].next;
        if (pre == -2 && next == -2)
            continue;
        else if (pre != -1 && next != -1)
        {
            nodeList[pre].next = nodeList[x].next;
            nodeList[next].pre = nodeList[x].pre;
        }
        else if (pre == -1 && next != -1)
        {
            nodeList[next].pre = pre;
        }
        else if (pre != -1 && next == -1)
        {
            nodeList[pre].next = next;
        }
        nodeList[x].next = -2;
        nodeList[x].pre = -2;
    }
}
