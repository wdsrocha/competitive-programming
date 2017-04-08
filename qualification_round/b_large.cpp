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
#define printList(x, y) for(int i=0;i<SZ(x);i++)cout<<setw(y)<<x[i];cout<<endl;

void fix(string& s, int idx)
{
	if (idx == 0) return;
	if (s[idx-1] > s[idx])
	{
		s[idx-1] -= (s[idx-1] != '0');
		s[idx] = '9';
		fix(s, idx-1);
	}
}


string solve(string& s)
{
	int index = -1;
	for (int i = 1; i < SZ(s); i++)
	{
		if (s[i-1] > s[i])
		{
			index = i;
			break;
		}
	}

	if (!~index) return s;
	fix(s, index);
	for (int i = index; i < SZ(s); i++)
		s[i] = '9';
	return s.substr(s[0]=='0');
}

signed main()
{_
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++)
	{
		string n;
		cin >> n;
		cout << "Case #" << tc << ": " << solve(n) << endl;
	}
	return 0;
}
