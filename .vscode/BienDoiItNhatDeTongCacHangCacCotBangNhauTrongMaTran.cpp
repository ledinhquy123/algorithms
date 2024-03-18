#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin  >> n;
        int a[n][n];
        int h[n] = {0}, c[n] = {0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
                h[i] += a[i][j];
                c[j] += a[i][j]; 
            }
        }
        int Max = max(*max_element(h, h + n), *max_element(c, c + n));
        int res = 0, i = 0, j = 0;
        while(i < n && j < n){
            int ans = min(Max - h[i], Max - c[j]);
            res += ans;
            h[i] += ans;
            c[j] += ans;
            if(h[i] == Max) ++i;
            if(c[j] == Max) ++j;
        }
        cout << res << endl;
    }
    return 0;
}