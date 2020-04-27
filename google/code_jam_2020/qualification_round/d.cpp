#include <bits/stdc++.h>
using namespace std;

#define int long long
#define oo ((int)1e9)
#define eb emplace_back
#define debug(x) cout << #x << " is " << x << endl;

int n;
char ok;
ofstream log_file("log.txt");

void solve() {
	string b(n, '_');
	for (int i = 0; i < 10; i++) {
		cout << to_string(i + 1) << endl;
		cin >> b[i];
	}
	cout << b << endl;

	cin >> ok;
	if (ok == 'N') exit(0);

	log_file << b << ' ' << ok << endl;
	return;
}

signed main() {
	ios_base::sync_with_stdio(0);

	int TC;
	cin >> TC >> n;
	for (int tc = 1; tc <= TC; tc++)
	{
		solve();
	}
	return 0;
}
