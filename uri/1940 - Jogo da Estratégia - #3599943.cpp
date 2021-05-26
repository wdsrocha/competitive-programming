#include <bits/stdc++.h>
using namespace std;
int main(){
    int p, r, maior=0, v=0, x;
    cin >> p >> r;
    int pt[p];
    for (int i = 0; i < p; i++) pt[i] = 0;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < p; j++){
            cin >> x;
            pt[j] += x;
            if (pt[j] >= maior){
                maior = pt[j];
                v = j + 1;
            }
        }
    }
    cout << v << endl;
    return 0;
}