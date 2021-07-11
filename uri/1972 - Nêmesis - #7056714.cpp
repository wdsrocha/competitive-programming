// Submitted at 19/05/2017 02:37:58
#include <bits/stdc++.h>
using namespace std;
#define INF ((int)1e9)
#define ii pair <int, int>
#define iii pair <int, ii>
#define vi vector <int>
#define vvi vector <vi>
int conv(char c) {
    return isdigit(c) ? c-'0' : 0;
}
int main() {
    int n, m;
    while (cin >> n >> m) {
        string grid[n];
        ii src;
        for (int i = 0;  i < n; i++) {
            cin >> grid[i];
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'H') {
                    src = ii(i, j);
                } else if (grid[i][j] == '.') {
                    grid[i][j] = '0';
                }
            }
        }
        vi di = {-1, 0, 1, 0};
        vi dj = { 0, 1, 0,-1};
        int ans = INF;
        priority_queue <iii, vector <iii>, greater <iii> > pq;
        pq.push(iii(0, src));
        vvi dist(n, vi(m, INF));
        dist[src.first][src.second] = 0;
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            ii u = cur.second;
            int i = u.first, j = u.second;
            if (cur.first > dist[i][j]) {
                continue;
            }
            if (grid[i][j] == 'E') {
                ans = dist[i][j];
                break;
            }
            for (int k = 0; k < 4; k++) {
                int p = i+di[k];
                int q = j+dj[k];
                if (p>=0 && p<n && q>=0 && q<m && grid[p][q] != '#' &&
                    dist[i][j] + conv(grid[p][q]) < dist[p][q]) {
                    dist[p][q] = dist[i][j] + conv(grid[p][q]);
                    pq.push(iii(dist[p][q], ii(p, q)));
                }
            }
        }
        if (ans != INF) {
            cout << ans << endl;
        } else {
            cout << "ARTSKJID\n";
        }
    }
    return 0;
}