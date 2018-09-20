#include <bits/stdc++.h>
using namespace std;

string s, p;
int ans;

inline bool isOk(int i) {
    for (int j = 0; j < (int)p.size(); j++)
        if (s[i+j] == p[j]) return 0;
    return 1;
}

int main() {
    cin >> s >> p;
    for (int i = 0; i <= (int)(s.size()-p.size()); i++) ans += isOk(i);
    cout << ans << endl;

    return 0;
}

