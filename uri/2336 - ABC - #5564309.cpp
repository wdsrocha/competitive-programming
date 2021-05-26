#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
#define MOD ((int)1e9 + 7)
#define ull unsigned long long
using namespace std;
int main()
{_
    unsigned long long ans;
    int k, i, sz;
    string str;
    
    while (cin >> str)
    {
        sz = str.size();    
        for (ans = i = 0; i < sz; i++)
        {
            k = str[i] - 'A';
            ans = ((26*(ans % MOD)) % MOD) + k;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}