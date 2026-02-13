#include <iostream>
using namespace std;

const int N = 1e5 + 3;

int st[N][18];
int LOG2[N];
int n, m;

typedef struct
{
    int value;
    int bucket_index;
} Array;
Array a[N];
typedef struct
{
    int value, left, right;
} Bucket;
Bucket bucket[N];

void get_input();
void init();

int main()
{
    get_input();
    init();
    while (m--) {
        int left, right;
        cin >> left >> right;
        int b_left = a[left].bucket_index;
        int b_right = a[right].bucket_index;
        if (b_left == b_right) {
            cout << b_right - b_left + 1 << endl;
        } else {
            int l_count, r_count;
            int lbr = bucket[b_left].right;
            int rbl = bucket[b_right].left;
            l_count = lbr - left + 1;
            r_count = right - rbl + 1;
            int len = b_right - b_left - 1;
            if (len == 0)
                cout << max(l_count, r_count) << endl;
            else {
                int start = b_left + 1, end = b_right - 1;
                int k = LOG2[len];
                int mid_count = max(st[start][k], st[end + 1 - (1 << k) + 1][k]);
                cout << max(l_count, max(mid_count, r_count)) << endl;
            }
        }
    }
    cin >> m;
    return 0;
}

void get_input()
{
    cin >> n >> m;
    int front = -1, count = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        cin >> a[i].value;
        if (i == 1)
            front = a[i].value;
        if (front == a[i].value)
            count++;
        else {
            front = a[i].value;
            bucket[j].value = count;
            bucket[j].left = i - count;
            bucket[j].right = i - 1;
            count = 1;
            j++;
        }
        if (i == n) {
            bucket[0].value = j;
            bucket[j].value = count;
            bucket[j].left = i - count + 1;
            bucket[j].right = i;
        }
    }
}

void init()
{
    LOG2[0] = -1;
    for (int i = 1; i <= n; i++)
        LOG2[i] = LOG2[i >> 1] + 1;
    int len = bucket[0].value;
    for (int i = 1; i <= len; i++)
        st[i][0] = bucket[i].value;
    for (int j = 1; j <= LOG2[len]; j++) {
        for (int i = 1; i + (1 << (j - 1)) <= len; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= len; i++) {
        for (int j = bucket[i].left; j <= bucket[i].right; j++)
            a[j].bucket_index = i;
    }
}