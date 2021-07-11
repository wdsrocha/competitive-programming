// Submitted at 18/09/2016 21:10:53
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
using namespace std;
#define maxn 10004
#define pb push_back
#define inf (int)1e9
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;
int n, m, u, v, w, cd, up, vp, i, j;
vi d[2];
vii adj[maxn];
struct State
{
    int weight, vertex, parity;
    State(int a, int b, int c)
    {
        weight = a;
        vertex = b;
        parity = c;
    }
    bool operator>(const State& x) const
    {
        return weight > x.weight;
    }};
int dijkstra(int s)
{
    d[0].assign(n+1, inf);
    d[1].assign(n+1, inf);
    priority_queue <State, vector <State>, greater <State> > pq;
    pq.push(State(d[0][s]=0, s, 0));
    while (!pq.empty())
    {
        State curr = pq.top(); pq.pop();
         u = curr.vertex;
        cd = curr.weight;
        up = curr.parity;
        if (cd > d[up][u]) continue;
        if (u==n && up==0) return d[0][n];
        for (j=0; j<(int)adj[u].size(); j++)
        {
            v = adj[u][j].first;
            w = adj[u][j].second;
            vp = up^1;
            if (d[up][u] + w < d[vp][v])
            {
                d[vp][v] = d[up][u] + w;
                pq.push(State(d[vp][v], v, vp));
            }}}
    return -1;
}
int main()
{_
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v >> w;
        adj[u].pb(ii(v, w));
        adj[v].pb(ii(u, w));
    }
    cout << dijkstra(1) << endl;
    return 0;
}