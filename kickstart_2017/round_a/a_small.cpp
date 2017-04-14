#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);
#define INF ((int)1e9)
#define MOD7 (INF + 7)
#define MOD11 (INF + 11)
#define EPS (1e-9)
#define PI (acos(-1))
#define SZ(x) ((int)x.size())
#define pb push_back
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define int ll
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
#define printList(x, y) for(int i=0;i<SZ(x);i++)cout<<setw(y)<<x[i];cout<<endl;

int n, m;

signed main()
{_
	int tc;
	cin >> tc;
	for (int tc_ = 1; tc_ <= tc; tc_++)
	{
		cin >> n >> m;

		int ans = 0;
		for (int i = 1; i < min(n, m); i++)
		{
			int i_ = i % MOD7;
			int n_ = (n - i) % MOD7;
			int m_ = (m - i) % MOD7;
			ans = (ans + (i_ * ((n_ * m_) % MOD7)) % MOD7) % MOD7;
		}

		cout << "Case #" << tc_ << ": " << ans << endl;
	}

	return 0;
}
