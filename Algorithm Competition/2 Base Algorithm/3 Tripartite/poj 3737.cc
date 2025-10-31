#include <cmath>
#include <iostream>

using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;
double s;

double radius(double angle)
{
    return sqrt(s / (PI * (1.0 + 1.0 / cos(angle))));
}

double V(double angle)
{
    double r = radius(angle);
    return PI * pow(r, 3) * tan(angle) / 3;
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> s) {
        double l = 0, r = PI / 2;
        while (r - l > eps) {
            double mid1 = l + (r - l) / 3;
            double mid2 = r - (r - l) / 3;
            if (V(mid1) > V(mid2))
                r = mid2;
            else
                l = mid1;
        }
        double rad = radius(l);
        printf("%.2f\n", V(l));
        printf("%.2f\n", rad * tan(l));
        printf("%.2f\n", rad);
    }
}