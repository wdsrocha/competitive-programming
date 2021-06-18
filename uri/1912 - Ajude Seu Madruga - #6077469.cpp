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
double spaceSearch(vi& a, double lo, double hi, double target)
{
    int n = SZ(a);
    while (lo < hi)
    {
        double m = lo + (hi - lo) / 2.0;
        double area = 0.0;
        for (int i = 0; i < n; i++)
            area += ((double)a[i] - m) * ((double)a[i] - m > 0);
        if (abs(area - target) < EPS) return m;
        else if (area - target < EPS) hi = m;
        else lo = m;
    }
    return -1;
}
signed main()
{_
    int n, area;
    while (cin >> n >> area && (n || area))
    {
        vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int total = accumulate(ALL(a), 0);
        if (area >= total || !area)
        {
            cout << (area > total ? "-.-" : ":D") << endl;
            continue;
        }
        double ans = spaceSearch(a, 0, *max_element(ALL(a)), area);
        cout << fixed << setprecision(4) << ans;
        cout << endl;
    }
    return 0;
}