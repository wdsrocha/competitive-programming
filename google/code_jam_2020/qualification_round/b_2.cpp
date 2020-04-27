#include <bits/stdc++.h>
using namespace std;

#define int long long
#define oo ((int)1e9)
#define eb emplace_back
#define debug(x) cout<<#x<<" is "<<x<<endl;

void solve() {
	string s, ans;
	cin >> s;
	int open_bracket_count = 0;
	for (int i = 0; i < s.size(); i++) {
		int digit = s[i] - '0';
		for (; open_bracket_count < digit; open_bracket_count++) ans += '(';
		for (; open_bracket_count > digit; open_bracket_count--) ans += ')';
		ans += s[i];
	}
	for (; open_bracket_count > 0; open_bracket_count--) ans += ')';
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}
