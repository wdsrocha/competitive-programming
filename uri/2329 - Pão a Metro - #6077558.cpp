#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);
#define INF ((int)1e9)
#define MOD7 (INF + 7)
#define MOD11 (INF + 11)
#define EPS (1e-7)
#define PI (acos(-1))
#define SZ(x) ((int)x.size())
#define pb push_back
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define int ll
#define ii pair <int, int>
#define vi vector <int>
#define vii vector <ii>
#define vvi vector <vi>
#define vvii vector <vii>
#define dd pair <double, double>
#define vd vector <double>
#define vdd vector <dd>
#define vvd vector <vd>
#define vvdd vector <vdd>
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cout<<#x<<" is "<<x<<endl;
#define printList(x, y) for(int i=0;i<SZ(x);i++)cout<<setw(y)<<x[i];cout<<endl;
int n, x, a[10002];
int p(int x)
{
    int value = 0;
    for (int i = 0; i < n; i++)
        value += a[i] / x;
    return value;
}
int spaceSearch(int lo, int hi)
{
    while (lo < hi)
    {
        int m = lo + (hi - lo) / 2;
        if (p(m) <= x) hi = m;
        else lo = m + 1;
    }
    return lo;
}
signed main()
{_
    cin >> x >> n; --x;
    int maxEle = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxEle = max(maxEle, a[i]);
    }
    cout << spaceSearch(1, maxEle) - 1 << endl;
    return 0;
}