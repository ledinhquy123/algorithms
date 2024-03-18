#include <bits/stdc++.h>
using namespace std;
//Con chuot trong me cung
int n, a[15][15];
char d[100];
void Try(int i, int j, int k){
    if(i == n && j == n){
        for(int i = 1; i <= k; i++){
            cout << d[i];
        }
        cout << " ";
        return;
    }
    if(a[i + 1][j] && i + 1 <= n){
        d[k] = 'D';
        a[i + 1][j] = 0;
        Try(i + 1, j, k + 1);
        //backtrack
        a[i + 1][j] = 1;
    }
    if(a[i][j + 1] && j + 1 <= n){
        d[k] = 'R';
        a[i][j + 1] = 0;
        Try(i, j + 1, k + 1);
        a[i][j + 1] = 1;
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) cin >> a[i][j];
        }
        if(a[1][1] == 0 || a[n][n] == 0){
            cout << "-1";
        }else{
            Try(1, 1, 1);
        }
        cout << endl;
    }

    return 0;
}