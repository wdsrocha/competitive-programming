#include <bits/stdc++.h>
using namespace std;

#define int long long
#define is pair<int, string>
#define oo ((int)1e9)
#define eb emplace_back
#define debug(x) cout << #x << " is " << x << endl;

set<int> join(set<int> a, set<int> b) {
	set <int> c;
	for (int k : c) {
		if (b.find(k) != b.end()) {
			c.insert(k);
		}
	}
	return c;
}

set<int> rangeSet(int lo, int hi) {
	set <int> interval;
	for (int i = lo; i <= hi; i++) {
		interval.insert(i);
	}
	return interval;
}

void solve() {
    const int N = 10000;
    int u;
    int m[N];
    int r[N];
    vector<is> mr(N);
    map<char, int> decrypt;
    map<char, set<int>> g;

    cin >> u;
    for (int i = 0; i < N; i++) {
        cin >> mr[i].first >> mr[i].second;
    }
    sort(mr.begin(), mr.end());
    for (int i = 0; i < 500; i++) {
        int m = mr[i].first;
        string r = mr[i].second;

		// premature optimization
        if (i and m == mr[i - 1].first and r == mr[i - 1].second) {
            continue;
        }
		// already found ans

        if (m <= 9) {
			if (g[m].size() == 1) continue;
            g[r[0]] = join(g[r[0]], rangeSet(1, m));
        } else if (r.size() < (int)log10(m) + 1) {
			m = (int)pow(10, r.size()) - 1;
		}
    }
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
