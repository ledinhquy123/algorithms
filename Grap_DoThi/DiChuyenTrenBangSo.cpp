#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
int a[501][501], d[501][501], used[505][505];
int n, m;
typedef pair<int, pair<int, int>> pi;
void Nhap(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            d[i][j] = 1e9;
            used[i][j] = false;
        }
    }
}
// d[i][j] : luu khoang cach ngan nhat tu dinh (1, 1) toi (i, j)
void Dijkstra(int i, int j){
    priority_queue<pi, vector<pi>, greater<pi>> q;
    d[i][j] = a[i][j];
    q.push({a[i][j], {i, j}});
    while(!q.empty()){
        pi top = q.top(); q.pop();
        if(!used[top.second.first][top.second.second]){
            used[top.second.first][top.second.second] = true;
            for(int k = 0; k < 4; k++){
                int i1 = top.second.first + dx[k];
                int j1 = top.second.second + dy[k];
                if(i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= m){
                    if(d[i1][j1] > d[top.second.first][top.second.second] + a[i1][j1]){
                        d[i1][j1] = d[top.second.first][top.second.second] + a[i1][j1];
                        q.push({d[i1][j1], {i1, j1}});
                    }
                }
            }
        }
    }
    cout << d[n][m];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nhap();
    Dijkstra(1, 1);

    return 0;
}