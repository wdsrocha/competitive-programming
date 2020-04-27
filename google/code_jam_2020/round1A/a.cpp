#include <bits/stdc++.h>
using namespace std;

#define int long long
#define oo ((int)1e9)
#define eb emplace_back
#define debug(x) cout << #x << " is " << x << endl;

int n;
string l, r, p;

void getZarr(string str, vector<int> &Z)
{
	int n = str.length();
	int L, R, k;
	L = R = 0;
	for (int i = 1; i < n; ++i)
	{
		if (i > R)
		{
			L = R = i;
			while (R < n && str[R - L] == str[R])
				R++;
			Z[i] = R - L;
			R--;
		}
		else
		{
			k = i - L;
			if (Z[k] < R - i + 1)
				Z[i] = Z[k];
			else
			{
				L = i;
				while (R < n && str[R - L] == str[R])
					R++;
				Z[i] = R - L;
				R--;
			}
		}
	}
}

void solve()
{
	cin >> n;
	l.clear();
	r.clear();
	bool fail = false;
	for (int i = 0; i < n; i++)
	{
		cin >> p;

		for (int j = 0; j < p.size(); j++)
		{
			if (p[j] == '*')
				break;
			if (j >= l.size())
			{
				l.push_back(p[j]);
			}
			else if (p[j] != l[j])
			{
				fail = true;
				break;
			}
		}

		for (int j = p.size() - 1, k = 0; j >= 0; j--, k++)
		{
			if (p[j] == '*')
				break;
			if (k >= r.size())
			{
				r.push_back(p[j]);
			}
			else if (p[j] != r[k])
			{
				fail = true;
				break;
			}
		}
	}

	if (fail)
	{
		cout << "*\n";
		return;
	}

	reverse(r.begin(), r.end());

	string concat = r + "$" + l;
	vector<int> z(concat.size());
	getZarr(concat, z);

	int toPop = 0;
	for (int i = 0; i < z.size(); i++)
	{
		if (z[i] + i == z.size())
		{
			toPop = max(toPop, z[i]);
		}
	}

	l.erase(l.size() - toPop);

	string ans = l + r;
	cout << (ans.size() <= 10000 ? ans : "*") << endl;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++)
	{
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}
