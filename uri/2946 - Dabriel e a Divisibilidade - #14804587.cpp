#include<bits/stdc++.h>
using namespace std;
string bits;
int m, divisor;
vector <int> ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> bits;
    cin >> m;
    while (m--) {
        cin >> divisor;
        int k = 0;
        for (char bit : bits) {
            k = (2 * k + (bit == '1')) % divisor;
        }
        if (!k) ans.push_back(divisor);
    }
    if (!ans.size()) {
        return cout << "Nenhum\n", 0;
    }
    sort(ans.begin(), ans.end());
    cout << ans[0];
    for (int i = 1; i < ans.size(); i++) {
        cout << ' ' << ans[i];
    }
    cout << endl;
    return 0;
}