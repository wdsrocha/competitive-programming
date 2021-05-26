#include <bits/stdc++.h>
using namespace std;
int mod(int out, int i, int n){
    int f = ((((10%n)*(i%n))%n) + 1)%n;
    if (f != 0){
        out++;
        return mod(out,f,n);
    }
    else return out;
}
int main(){
    int n;
    while (cin>>n){
        if (n==1) cout << 1;
        else cout << mod(2,1,n);
        cout << endl;
    }
    return 0;
}