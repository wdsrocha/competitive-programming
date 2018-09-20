#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define oo 1000000009
#define ll long long

ll ft[MAXN];
int n, m, _;
struct P { int l, r; } p[MAXN];

int sum(int x) {
    ll ans = 0;
    for (; x; x -= x&-x) ans += ft[x];
    return ans;
}

void upd(int x, int v) {
    for (; x < MAXN; x += x&-x) ft[x] += v;
}

int main() {
    ios_base::sync_with_stdio(0);
    scanf("%d %d", &_, &_);
    scanf("%d %d", &n, &m);

    int nm = n+m;
    for (int i = 1; i <= nm; i++) {
        scanf("%d %d", &p[i].l, &p[i].r);
        if (i > n) {
            p[i].l -= oo;
            p[i].r += oo;
        }
    }
    
    sort(p+1, p+nm+1, [](P a, P b)->bool { return a.r < b.r; });
    for (int i = 1; i <= nm; i++) p[i].r = i;
    sort(p+1, p+nm+1, [](P a, P b)->bool { return a.l < b.l; });

    ll ans = 1;
    for (int i = nm+1; --i;) {
        ans += 1+sum(p[i].r);
        upd(p[i].r, 1);
    }
    printf("%lld\n", ans);

    return 0;
}

