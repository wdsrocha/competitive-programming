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

int bfs(string src, string dest, int k)
{
	int n = src.size();
	queue <string> q;
	q.push(src);
	map <string, int> dist;
	dist[src] = 1;
	while (!q.empty())
	{
		string u = q.front(); q.pop();
		if (u == dest) return dist[u];

		for (int i = 0; i <= n-k; i++)
		{
			string v = u;
			for (int j = 0; j < k; j++)
				v[i+j] = v[i+j] == '+' ? '-' : '+';
			if (dist[v] == 0)
			{
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return INF;
}

signed main()
{
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++)
	{
		int k;
		string src, dest;
		cin >> src >> k;
		dest = string(src.size(), '+');
		int ans = bfs(src, dest, k);


		cout << "Case #" << tc << ": ";
		if (ans != INF) cout << ans - 1;
		else cout << "IMPOSSIBLE";
		cout << endl;
	}
	return 0;
}
