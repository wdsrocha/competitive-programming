#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);
#define INF ((int)1e9)
#define MOD (100000007)
#define EPS (1e-9)
#define PI (acos(-1))
#define sz(x) ((int)x.size())
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ii pair <int, int>
#define vi vector <ll>
#define vii vector <ii>
#define vvi vector <vi>
#define vvii vector <vii>
int n, m, i, j, k;
ll x, y, d;
vi fat, invfat;
void ee(ll a, ll b)
{
    if (!b){ x = 1, y = 0, d = a; return; }
    ee(b, a % b);
    int x_ = y;
    int y_ = x - (a / b)*y;
    x = x_;
    y = y_;
}
ll inv(ll a)
{
    if (invfat[a]) return invfat[a];
    ee(fat[a], MOD);
    x += (x < 0)*MOD;
    // if (x < 0) x += MOD;
    invfat[a] = x;
    return x;
}
void genFat(int n)
{
    fat = vi(n + 1);
    invfat = vi(n + 1);
    fat[0] = 1;
    invfat[0] = 1;
    invfat[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        fat[i] = (fat[i - 1] * i) % MOD;
        inv(i);
    }
}
int main()
{_
    genFat(10002);
    for (string str; cin >> str && str != "0";)
    {
        vi freq(27);
        for (i = 0; i < sz(str); i++)
            freq[str[i] - 'a']++;
        ll ans = fat[sz(str)];
        for (i = 0; i < 27; i++)
            ans = (ans * inv(freq[i])) % MOD;
        cout << ans << endl;
    }
    return 0;
}