#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
#define INF ((int)1e9)
#define MOD7 (INF + 7)
#define MOD11 (INF + 11)
#define EPS (1e-9)
#define PI (acos(-1))
#define SZ(x) ((int)x.size())
#define eb emplace_back
#define pb eb
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define ii pair <int, int>
#define vi vector <int>
#define vii vector <ii>
#define vvi vector <vi>
#define vvii vector <vii>
#define dd pair <double, double>
#define vd vector <double>
#define vdd vector <dd>
#define vvd vector <vd>
#define vvdd vector <vdd>
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cout<<#x<<" is "<<x<<endl;

double perimeter(ii x) {
    return 2.0*PI*x.fi*x.se;
}

double radius(int r) {
    return PI*r*r;
}

bool cmp(ii a, ii b) {
    return perimeter(a) > perimeter(b);
}

bool cmpaux(ii a, ii b) {
    return a.fi > b.fi;
}

signed main()
{
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++)
	{
        int n, k;
        cin >> n >> k;
        vii a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].fi >> a[i].se;
        }

        sort(ALL(a), cmpaux);
        double best = 0.0;
        for (int i = 0; i < n-k+1; i++) {
            vii b(a.begin()+i+1, a.end());
            sort(ALL(b), cmp);

            double value = radius(a[i].fi) + perimeter(a[i]);
            for (int j = 0; j < k-1; j++) {
                value += perimeter(b[j]);
            }
            best = max(best, value);
        }

		cout << "Case #" << tc << ": ";
        cout << fixed << setprecision(9) << best << endl;
	}
	return 0;
}
