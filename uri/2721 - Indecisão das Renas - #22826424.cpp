#include <bits/stdc++.h>
using namespace std;

int k, total;

string renas[] = {"Dasher", "Dancer", "Prancer", "Vixen", "Comet", "Cupid", "Donner", "Blitzen", "Rudolph"};

int main() {
    for (int i = 0; i < 9; i++) {
        cin >> k;
        total += k;
    }

    int indice = ((total - 1) % 9);
    cout << renas[indice] << endl;
    

    return 0;
}

// 1 2 3 4 5 6 7 8 9
// total = 45
//       = 45 - 9
//       = 36
//       = 36 - 9
//       = 27
//       = 27 - 9
//       = 18 
//       = 18 - 9
//       = 9
//       = 9 - 9
//       = 0

// 45 % 9

// 1 2 1 2 1 2 1 2 1
// total = 13
// total = 13 - 9
// total = 4
// 
// total = 5 => 5 - 1 = 4 (resposta)
// 0 Dasher
// 1 Dancer
// 2 Prancer
// 3 Vixen
// 4 Comet
// 5 Cupid
// 6 Donner
// 7 Blitzen
// 8 Rudolph