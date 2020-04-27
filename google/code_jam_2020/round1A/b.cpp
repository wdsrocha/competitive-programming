#include <bits/stdc++.h>
using namespace std;

#define int long long
#define oo ((int)1e9)
#define eb emplace_back
#define debug(x) cout << #x << " is " << x << endl;

int n;

void solve()
{
    cin >> n;
    cout << "\n1 1\n";
    n--;

    for (int i = 2; n; i++) {
        if (n - (i - 1) >= 0) {
            n -= i - 1;
            cout << i << " 2\n";
        } else {
            n--;
            cout << i - 1 << " 1\n";
        }
    }
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
