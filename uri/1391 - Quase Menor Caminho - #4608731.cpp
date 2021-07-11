// Submitted at 13/06/2016 01:54:17
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
#define inf 1000000000
#define maxn 505
#define on 1
#define off 0
using namespace std;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;
int n, m, i, j, u, v, w, cd, s, e, sp;
ii curr;
vi d, d1, d2, node;
vii g_s[maxn], g_e[maxn];
vi dijkstra(vii adj[], int s, int e){
    d.assign(n, inf);
    priority_queue<ii, vii, greater<ii> > pq;
    pq.push(make_pair(d[s]=0, s));
    while (!pq.empty()){
        curr = pq.top(); pq.pop();
        cd=curr.first, u=curr.second;
        if (cd>d[u]) continue;
        for (j=0; j<adj[u].size(); j++){
            v=adj[u][j].first, w=adj[u][j].second;
            if (d[u]+w<d[v] && node[v]==on) pq.push(make_pair(d[v]=d[u]+w, v));
        }
    }
    return d;
}
int main(){_
    while (cin >> n >> m && (n||m)){
        cin >> s >> e;
        node.assign(n, on);
        while (m--){
            cin >> u >> v >> w;
            g_s[u].push_back(make_pair(v, w));
            g_e[v].push_back(make_pair(u, w));
        }
        d1 = dijkstra(g_s, s, e); sp = d1[e];
        d2 = dijkstra(g_e, e, s);
        for (i=0; i<n; i++) if (d1[i]+d2[i]==sp && i!=s && i!=e) node[i]=off;
        for (j=0; j<g_s[s].size(); j++) if (g_s[s][j].first==e) g_s[s].erase(g_s[s].begin()+j);
        d = dijkstra(g_s, s, e);
        cout << (d[e]!=inf ? d[e] : -1) << endl;
        for (i=0; i<n; i++) g_s[i].clear(), g_e[i].clear();
        node.clear();
    }
    return 0;
}