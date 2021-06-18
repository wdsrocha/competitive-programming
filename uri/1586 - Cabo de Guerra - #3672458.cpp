#include <bits/stdc++.h>
using namespace std;
int binarySearch(int v[], int n){
    int bot=0,top=n;
    while(bot<=top){
        long long int a=0,b=0;
        int mid=(bot+top)/2;
        for(int i=mid;i>=0;i--) a+=v[i]*(mid-i+1);
        for(int i=mid+1;i<n;i++)b+=v[i]*(i-mid);
        if(a<b) bot=mid+1;
        else if(a>b) top=mid-1;
        else return mid;
    }
    return -1;
}
int main() {
    int n;
    while(cin>>n&&n!=0){
        int v[n];
        string nome[n];
        for(int i=0;i<n;i++){
            cin>>nome[i];
            v[i]=0;
            for(int j=0;j<nome[i].length();j++)v[i]+=nome[i][j];
        }
        int ans=binarySearch(v,n);
        if(ans!=-1) cout << nome[ans] << endl;
        else cout << "Impossibilidade de empate.\n";
    }
}