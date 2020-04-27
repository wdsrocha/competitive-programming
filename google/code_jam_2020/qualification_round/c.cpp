#include <bits/stdc++.h>
using namespace std;

#define int long long
#define oo ((int)1e9)
#define eb emplace_back
#define debug(x) cout<<#x<<" is "<<x<<endl;

struct Task {
	int t0, tf, id;
};

void solve() {
	int n;
	cin >> n;

	vector <Task> tasks(n);
	for (int i = 0; i < n; i++) {
		cin >> tasks[i].t0 >> tasks[i].tf;
		tasks[i].id = i;
	}

	sort(tasks.begin(), tasks.end(), [](Task a, Task b) {
		if (a.t0 != b.t0) return a.t0 < b.t0;
		return a.tf < b.tf;
	});

	int at = 0, bt = 0;
	string ans(n, '#');
	for (auto task : tasks) {
		if (at <= task.t0) {
			at = task.tf;
			ans[task.id] = 'C';
		} else if (bt <= task.t0) {
			bt = task.tf;
			ans[task.id] = 'J';
		} else {
			cout << "IMPOSSIBLE\n";
			return;
		}
	}
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
