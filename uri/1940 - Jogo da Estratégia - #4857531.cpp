#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
using namespace std;
int freq[555];
int main()
{
    int n, m, nm, k, great=0, ans;
    cin >> n >> m; nm = n*m;
    for (int i=0, j=0; i<nm; i++, j=(j+1)%n)
    {
        cin >> k;
        freq[j]+=k;
        if (freq[j]>=great)
        {
            great=freq[j];
            ans = j+1;
        }
    }
    cout << ans << endl;
    return 0;
}