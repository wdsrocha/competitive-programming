// Submitted at 06/06/2016 16:51:50
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define endl '\n'
#define maxn 100
#define inf 1000000000
using namespace std;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
vi d;
vii adj[maxn];
string su, sv;
map <string, int> msi;
int x, m, n, i, j, u, v, w, cd, k, h, t, tot;
int conv(string s){return msi[s]=msi[s]?msi[s]:++k;}
int dijkstra(int s, int e){
    d.assign(n+1, inf);
    priority_queue <ii, vii, greater <ii> > pq;
    pq.push(make_pair(d[s]=0, s));
    while (!pq.empty()){
        ii c=pq.top(); pq.pop();
        u=c.second; cd=c.first;
        if (cd>d[u]) continue;
        if (u==e) return d[e];
        for (j=0; j<adj[u].size(); j++){
            v=adj[u][j].first, w=adj[u][j].second;
            if (d[u]+w<d[v]) pq.push(make_pair(d[v]=d[u]+w, v));
        }
    }
    return d[e];
}
int main(){_
    while (cin >> x >> m >> n && (x||m||n)){
        for (k=0, i=m; i--;){
            cin >> su >> sv >> w;
            u=conv(su); v=conv(sv);
            adj[u].push_back(make_pair(v, w));
        }
        t = dijkstra(msi["varzea"], msi["alto"]);
        for (tot=(x = x<=30 ? 30 : 50) + t, h=0; tot>=0; tot-=60, h++);
        cout << (h+16)%24 << ':' << (60+tot<10 ? "0":"") << 60+tot << endl;
        cout << (x+t > 60 ? "Ira se atrasar":"Nao ira se atrasar") << endl;
        for (i=1; i<=n; i++) adj[i].clear();
        msi.clear(); d.clear();
    }
    return 0;
}