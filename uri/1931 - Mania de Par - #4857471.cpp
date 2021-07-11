// Submitted at 01/08/2016 19:15:07
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
#define inf (int)1e9
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define maxn 10100
using namespace std;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
int n, m, u, v, w, s, s1, s2, i, j, k, cd, num[maxn];
vii aux[maxn], graph[maxn];
void debug();
int dijkstra()
{
    vi d(maxn, inf);
    priority_queue <ii, vii, greater<ii> > pq;
    pq.push(mp(d[1]=0, 1));
    while (!pq.empty())
    {
        ii curr = pq.top(); pq.pop();
        cd = curr.fi;
        u = curr.se;
        if (cd>d[u]) continue;
        if (u==n) return d[u];
        for (j=0; j<graph[u].size(); j++)
        {
            v = graph[u][j].fi;
            w = graph[u][j].se;
            if (d[u]+w<d[v])
                pq.push(mp(d[v]=d[u]+w, v));
        }
    }
    return -1;
}
int main()
{
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v >> s;
        aux[u].pb(mp(v, s));
        aux[v].pb(mp(u, s));
    }
    for (u=1; u<=n; u++)
    {
        num[u]=1;
        for (j=0; j<aux[u].size(); j++)
        {
            v = aux[u][j].fi;
            s1 = aux[u][j].se;
            for (k=0; k<aux[v].size(); k++)
            {
                w = aux[v][k].fi;
                if (num[w]) continue;
                s2 = aux[v][k].se;
                graph[u].pb(mp(w, s1+s2));
                graph[w].pb(mp(u, s1+s2));
            }
        }
    }
    cout << dijkstra() << endl;
    //debug();
    return 0;
}
void debug()
{
    for (u=1; u<=n; u++)
    {
        printf("%d:", u);
        for (j=0; j<aux[u].size(); j++)
            printf(" (%d,%d)", aux[u][j].fi, aux[u][j].se);
        printf("\n");
    }
    printf("\n");
    for (u=1; u<=n; u++)
    {
        printf("%d:", u);
        for (j=0; j<graph[u].size(); j++)
            printf(" (%d,%d)", graph[u][j].fi, graph[u][j].se);
        printf("\n");
    }
}