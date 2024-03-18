#include<bits/stdc++.h>
using namespace std;
int n, m;
int d[105][105];
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n + 1; i++){
        for(int j = 1; j <= n + 1; j++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = 1e9;
        }
    }
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        d[x][y] = d[y][x] = w;
        // d[x][y] = d[y][x] = min(d[x][y], 1ll * w);
    }
    for(int k = 1; k <= n + 1; k++){
        for(int i = 1; i <= n + 1; i++){
            for(int j = 1; j <= n + 1; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        cout << d[x][y] << endl;
    }
}
int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();

    return 0;
}