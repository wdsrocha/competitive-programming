#include <bits/stdc++.h>
using namespace std;

#define int long long
#define oo ((int)1e9)
#define eb emplace_back
#define debug(x) cout << #x << " is " << x << endl;

int n, m;

struct Cell {
    int i, j, v;
    Cell *u; // up
    Cell *r; // right
    Cell *l; // ...
    Cell *d;
    Cell *nxtU; // up
    Cell *nxtR; // right
    Cell *nxtL; // ...
    Cell *nxtD;
    bool ok;
};

void solve()
{
    cin >> n >> m;

    vector <vector <Cell*>> ref(n + 1, vector <Cell*>(m + 1, NULL));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            Cell *cell = new Cell();
            cin >> cell->v;
            cell->i = i;
            cell->j = j;
            cell->ok = true;
            ref[i][j] = cell;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            Cell *cell = ref[i][j];
            if (i > 1) cell->u = ref[i - 1][j];
            if (j < m) cell->r = ref[i][j + 1];
            if (i < n) cell->d = ref[i + 1][j];
            if (j > 1) cell->l = ref[i][j - 1];
        }
    }

    int ans = 0;
    for (int round = 1;; round++) {
        int players = 0;
        int feijoada = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (ref[i][j] == NULL) continue;
                players++;
                Cell *cell = ref[i][j];

                ans += cell->v;
                int sum = 0;
                int cnt = 0;
                if (cell->u != NULL) {
                    sum += cell->u->v;
                    cnt++;
                }
                if (cell->r != NULL) {
                    sum += cell->u->v;
                    cnt++;
                }
                if (cell->d != NULL) {
                    sum += cell->u->v;
                    cnt++;
                }
                if (cell->l != NULL) {
                    sum += cell->u->v;
                    cnt++;
                }
                if (cnt == 0) {
                    feijoada++;
                    continue;
                }
                cout << "td bem" << endl;

                double avg = (1.0 * sum) / cnt;
                if (avg > cell->v) {
                    if (cell->u != NULL) {
                        cell->u->nxtD = cell->d;
                    }
                    if (cell->r != NULL) {
                        cell->r->nxtL = cell->l;
                    }
                    if (cell->d != NULL) {
                        cell->d->nxtU = cell->u;
                    }
                    if (cell->l != NULL) {
                        cell->l->nxtR = cell->r;
                    }
                    cell->ok = false;
                } else {
                    feijoada++;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (ref[i][j] == NULL) continue;
                Cell *cell = ref[i][j];
                if (cell->ok == false) {
                    ref[i][j] = NULL;
                } else {
                    cell->u = cell->nxtU;
                    cell->r = cell->nxtR;
                    cell->d = cell->nxtD;
                    cell->l = cell->nxtL;
                }
            }
        }

        if (players == feijoada) {
            break;
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++)
    {
        cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}
