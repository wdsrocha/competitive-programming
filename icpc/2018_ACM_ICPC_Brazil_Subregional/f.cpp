#include <bits/stdc++.h>
using namespace std;
#define C 1003
#define T 86404
#define oo 0x3f3f3f3f

int n, k, c, t_max, start, dp[T][1025];
int finish[C], value[C], stage[C];
vector <int> show_at[T];

int main() {
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        while (k--) {
            scanf("%d %d %d", &start, finish+c, value+c);
            t_max = max(t_max, finish[c]+1);
            show_at[start].push_back(c);
            stage[c] = i;
            c++;
        }
    }

    for (int m = 1<<n; m--;) dp[t_max][m] = -oo;
    dp[t_max][(1<<n)-1] = 0;

    for (int t = t_max; t--;) {
        for (int m = 1<<n; m--;) {
            dp[t][m] = dp[t+1][m];
            for (int show : show_at[t]) {
                int nxt_t = finish[show];
                int nxt_m = m|(1<<stage[show]);
                dp[t][m] = max(dp[t][m], dp[nxt_t][nxt_m]+value[show]);
            }
        }
    }

    if (dp[0][0] <= 0) puts("-1");
    else printf("%d\n", dp[0][0]);

    return 0;
}

