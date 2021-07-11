// Submitted at 10/08/2017 12:47:48
#include <bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define vi vector <int>
#define vii vector <ii>
#define INF (1000000000)
#define pack(u, c) (27*u+c)
#define unpack(k) ii(k/27, k%27)
#define eb emplace_back
#define MAXN (110100)
// n is 0-index
// 0 is dummy, 1-26 are alphabet
int n;
vii adj[MAXN];
unordered_map <string, int> languages;
void init() {
    n = 0;
    for (int i = 0; i < MAXN; i++) {
        adj[i].clear();
    }
    languages.clear();
}
int conv(string& s) {
    if (languages.find(s) == languages.end()) {
        languages[s] = n++;
    }
    return languages[s];
}
int main() {
    int m, u, v, w, c, dst;
    string su, sv, sw;
    while (cin >> m and m) {
        init();
        cin >> su >> sv;
        conv(su);
        dst = conv(sv);
        while (m--) {
            cin >> su >> sv >> sw;
            u = conv(su);
            v = conv(sv);
            w = sw.size();
            c = sw[0]-'a'+1;
            for (int i = 0; i < 27; i++) {
                if (i != c) {
                    adj[pack(u, i)].eb(pack(v, c), w);
                    adj[pack(v, i)].eb(pack(u, c), w);
                }
            }
        }
        int ans = -1;
        vi dist(27*n+1, INF);
        dist[0] = 0;
        priority_queue <ii, vii, greater <ii> > pq;
        pq.push(ii(0, 0));
        while (!pq.empty()) {
            ii curr = pq.top(); pq.pop();
            u = curr.second;
            //cout << unpack(u).first << ":\n";
            if (curr.first > dist[u]) {
                continue;
            }
            if (unpack(u).first == dst) {
                ans = dist[u];
                break;
            }
            for (auto nxt : adj[u]) {
                v = nxt.first;
                w = nxt.second;
                //cout << ' ' << unpack(v).first << ' ' << w << endl;
                if (dist[u]+w < dist[v]) {
                    dist[v] = dist[u]+w;
                    pq.push(ii(dist[v], v));
                }
            }
        }
        if (ans != -1) {
            cout << ans;
        } else {
            cout << "impossivel";
        }
        cout << endl;
    }
    return 0;
}