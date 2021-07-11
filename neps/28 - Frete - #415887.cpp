#include<bits/stdc++.h>
using namespace std;
#define N 102
// 1 bilhão pra cima ta ok
#define INF 1000000009

int n, m, u, v, w, dist[N], processed[N];
vector<pair<int, int> > adj[N];

int dijkstra() {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        processed[i] = 0;
    }
    dist[1] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({ 0, 1 });

    while(pq.size()) {
        int u = pq.top().second;
        pq.pop();

        if (processed[u]) {
            continue;
        }
        processed[u] = 1;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({ -dist[v], v });
            }
        }
    }

    return dist[n];
}

int main() {
    cin >> n >> m;
    while (m--) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << dijkstra() << endl;

    return 0;
}