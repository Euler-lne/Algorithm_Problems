#include <cmath>
#include <iostream>
#include <vector>

const double PI = acos(-1.0);

using namespace std;

typedef struct Node {
    int x, y;
    Node() : x(0), y(0) {}
    Node(int _x, int _y) : x(_x), y(_y) {}
} Node;
Node node_arr[35];

double eps = 1e-9;
int n;

double caculate(double angle)
{
    double xi = 1000000000, yi = 1000000000, xa = -1000000000, ya = -1000000000;
    for (int i = 1; i <= n; i++) {
        double original_x = node_arr[i].x;
        double original_y = node_arr[i].y;
        double xt = original_x * cos(angle) - original_y * sin(angle);
        double yt = original_x * sin(angle) + original_y * cos(angle);
        xi = min(xi, xt);
        xa = max(xa, xt);
        yi = min(yi, yt);
        ya = max(ya, yt);
    }
    return max(ya - yi, xa - xi);
}

double caculate()
{
    double l = 0, r = PI;
    while (r - l > eps) {
        double mid1 = (r - l) / 3 + l;
        double mid2 = r - (r - l) / 3;
        if (caculate(mid1) > caculate(mid2))
            l = mid1;
        else
            r = mid2;
    }
    double ans = caculate(l);
    return ans * ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> node_arr[i].x >> node_arr[i].y;
        printf("%.2f\n", caculate());
    }
    return 0;
}