#include <bits/stdc++.h>
using namespace std;
#define N 1003

int n, m, l, k;
bitset <N> ans, a[N];

inline void read(bitset <N>& bs) {
    scanf("%d", &l);
    while (l--) {
        scanf("%d", &k);
        bs.set(k);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    scanf("%d %d", &n, &m);
    read(ans);
    for (int i = 0; i < 2*n; i++) {
        if (i < n) read(a[i]);
        ans ^= a[i-(i >= n)*n];
        if (ans.none()) return printf("%d\n", i+1), 0;
    }
    printf("%d\n", -1);

    return 0;
}
