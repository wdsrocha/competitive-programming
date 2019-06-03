#include <bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define oo 0x3f3f3f3f
#define N 100005

int n, m;
int dist[N], pred[N];
vector <ii> adj[N];

bool dijkstra(int from, int to = -1) {
    memset(dist, oo, sizeof dist);
    memset(pred, -1, sizeof pred);
    dist[from] = 0;
    set <ii> q;
    q.insert(ii(0, from));
    while (q.size()) {
        int u = q.begin()->second;
        q.erase(q.begin());
        if (u == to) return true;
        for (ii vw : adj[u]) {
            int v = vw.first;
            int w = vw.second;
            if (dist[u] + w < dist[v]) {
                q.erase(ii(dist[v], v));
                pred[v] = u;
                dist[v] = dist[u] + w;
                q.insert(ii(dist[v], v));
            }
        }
    }
    return false;
}

vector <int> getPath(int to) {
    vector <int> path;
    for (int u = to; u != -1; u = pred[u]) {
        path.emplace_back(u);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    return 0;
}