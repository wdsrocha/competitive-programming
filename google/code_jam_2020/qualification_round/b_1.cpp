#include <bits/stdc++.h>
using namespace std;

#define int long long
#define oo ((int)1e9)
#define eb emplace_back
#define debug(x) cout<<#x<<" is "<<x<<endl;

void solve() {
	string s, t;
	char last_c = '0';
	cin >> s;
	s = '#' + s + '#';
	for (int i = 1; i < s.size(); i++) {
		char c = s[i];
		if (c == '1' and last_c != '1') {
			t += '(';
		} else if (c != '1' and last_c == '1') {
			t += ')';
		}
		t += c;
		last_c = c;
	}

	t.pop_back();
	cout << t << endl;
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
