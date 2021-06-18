#include<bits/stdc++.h>
using namespace std;
#define int long long
#define _ ios_base::sync_with_stdio(0);
#define MAXN 100005
int n, d[MAXN], freq[MAXN], sum_d[MAXN];
void counting_sort() {
    for (int i = 1; i <= n; i++) freq[d[i]]++;
    for (int i = n, j = 0; i >= 0; i--) {
        while (freq[i]--) d[++j] = i;
        freq[i] = 0;
    }
}
signed main() {_
    while (cin >> n) {
        int holds = 1;
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
            holds &= (d[i] < n);
        }
        if (holds) counting_sort();
        for (int k = 1; k <= n; k++) {
            sum_d[k] = sum_d[k-1] + d[k];
        }
    
        int p = n;
        for (int k = 1; k <= n; k++) {
            while (k > d[p] && k < p) p--;
            while (k > p) p++;
            int sum = k*(p-k) + sum_d[n] - sum_d[p];
            holds &= (sum_d[k] <= k*(k-1LL) + sum);
        }
        holds &= (sum_d[n]%2LL == 0);
        cout << (holds ? "" : "im") << "possivel\n";
    }
    return 0;
}