#include <bits/stdc++.h>
using namespace std;

#define int long long
#define oo ((int)1e9)
#define eb emplace_back
#define debug(x) cout << #x << " is " << x << endl;

void solve()
{
	int x, y;
	string s;
	cin >> x >> y >> s;
	s += "$"; // just to run one more time
	int n = s.size();
	int curr_time = 0;
	int steps_to_reach;
	for (int i = 0; i < n; i++)
	{
		steps_to_reach = abs(x) + abs(y);
		if (steps_to_reach <= curr_time)
		{
			cout << curr_time << endl;
			return;
		}
		curr_time++;
		char c = s[i];
		if (c == 'N') y++;
		if (c == 'E') x++;
		if (c == 'S') y--;
		if (c == 'W') x--;
	}
	cout << "IMPOSSIBLE\n";
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
