#include <bits/stdc++.h>
using namespace std;

#define int long long
#define oo ((int)1e9)
#define eb emplace_back
#define debug(x) cout<<#x<<" is "<<x<<endl;

int a[102][102];

void solve() {
	int n;
	cin >> n;

	int trace = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (i == j) {
				trace += a[i][j];
			}
		}
	} 

	unordered_set <int> s;

	int repeated_rows = 0;
	for (int i = 1; i <= n; i++) {
		s.clear();
		for (int j = 1; j <= n; j++) {
			s.insert(a[i][j]);
		}
		if (s.size() != n) {
			repeated_rows++;
		}
	}

	int repeated_cols = 0;
	for (int j = 1; j <= n; j++) {
		s.clear();
		for (int i = 1; i <= n; i++) {
			s.insert(a[i][j]);
		}
		if (s.size() != n) {
			repeated_cols++;
		}
	}

	cout << trace << ' ' << repeated_rows << ' ' <<  repeated_cols << endl;
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
