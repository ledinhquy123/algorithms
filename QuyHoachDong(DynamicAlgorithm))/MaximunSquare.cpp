#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    int res = -1e9;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j]){
                if(i == 0 || j == 0) a[i][j] = a[i][j];
                else{
                    a[i][j] += min({a[i - 1][j], a[i][j - 1], a[i - 1][j - 1]});
                }
            }
            res = max(res, a[i][j]);
        }
    }
    cout << res;
    return 0;
}