#include <bits/stdc++.h>
using namespace std;
#define int long long
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
int m;
inline int fexp(int b, int e)
{
    int x = 1;
    for (; e; b = (b * b) % m , e /= 2) if (e & 1) x = ((x % m) * b) % m;
    return x;
}
signed main()
{
    int n;
    while (cin >> n)
    {
        m = pow(10, (int)log10(n) + 1);
        cout << (fexp(n, n) == n ? "SIM" : "NAO") << endl;
    }
    return 0;
}