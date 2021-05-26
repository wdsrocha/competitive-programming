#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
#define mod 131071
using namespace std;
typedef long long ll;
char c;
string s;
ll n, i, ans;
ll fexp(ll b, ll e){
    for (ans=1; e; e>>=1){
        if (e&1) ans=(ans*b)%mod;
        b=(b*b)%mod;
    }
    return ans;
}
int main(){_
    while (cin >> c){
        if (c!='#') s+=c;
        else{
            reverse(s.begin(), s.end());
            for (n=i=0; i<s.size(); i++) n+=(s[i]=='1')*fexp(2,i);
            cout << (n%mod ? "NO" : "YES") << endl;
            s="";
        }}
    return 0;
}