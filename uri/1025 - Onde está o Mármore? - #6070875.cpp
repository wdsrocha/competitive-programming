#include <bits/stdc++.h>
using namespace std;
int a[10003];
int lowerBound(int l, int r, int x)
{
    while (l < r)
    {
        int m = (l + r) / 2;
        if (a[m] >= x) r = m;
        else l = m + 1;
    }
    return a[l] == x ? l : -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    a[0] = -1;
    int n, q, tc = 0;
    while (cin >> n >> q && (n || q))
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a, a + n + 1);
        cout << "CASE# " << ++tc << ":\n";
        while (q--)
        {
            int target;
            cin >> target;
            int index = lowerBound(1, n, target);
            cout << target;
            if (index == -1) cout << " not found";
            else cout << " found at " << index;
            cout << endl;
        }
    }
    return 0;
}