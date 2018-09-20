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

signed main()
{
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++)
	{
        int n, r, ry, y, yb, b, br;
        cin >> n >> r >> ry >> y >> yb >> b >> br;
        vii colors = {{r, 'R'}, {y, 'Y'}, {b, 'B'}};
        sort(ALL(colors));

		cout << "Case #" << tc << ": ";
        if (colors[2].fi > (int)(n/2)) {
            cout << "IMPOSSIBLE";
        } else {
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0 && colors[2].fi) {
                    cout << (char)colors[2].se;
                    --colors[2].fi;
                } else if (colors[1].fi > colors[0].fi) {
                    cout << (char)colors[1].se;
                    --colors[1].fi;
                } else {
                    cout << (char)colors[0].se;
                    --colors[0].fi;
                }
            }
        }
		cout << endl;
	}
	return 0;
}
