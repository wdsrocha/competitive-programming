#include <bits/stdc++.h>
using namespace std;
#define PI ((double)acos(-1))
double n, l, b, B, H;
double f(double x) { return ((B - b) / H) * x + b; }
double spaceSearch(double lo, double hi, double target)
{
    for (int i = 0; i < 100; i++)
    {
        double x = lo + (hi - lo) / 2.0;
        double V = (1.0 / 3.0) * PI * x * (f(x) * f(x) + b * b + b * f(x));
        if (V > target) hi = x;
        else if (V < target) lo = x;
    }
    return lo;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> l >> b >> B >> H;
        double target = l / n;
        cout << fixed << setprecision(2) << spaceSearch(0, H, target) << endl;
    }
    return 0;
}