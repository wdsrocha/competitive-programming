#include <bits/stdc++.h>
using namespace std;
int v[100];
int main()
{
    ios_base::sync_with_stdio(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m, f, l = 0, r = 0;
        cin >> n >> m >> f;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            l = max(l, v[i]);
            r += v[i];
        }
        while (l < r)
        {
            int mid = (l + r) / 2;
            int cnt = 1, cum = 0;
            for (int i = 0; i < n; i++)
            {
                cum += v[i];
                if (cum > mid) cnt++, cum = v[i];
            }
            if (cnt > m) l = mid + 1;
            else if (cnt <= m) r = mid;
        }
        cout << l << " $" << m * f * l << endl;
    }
    return 0;
}