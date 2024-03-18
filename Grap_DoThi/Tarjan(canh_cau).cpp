#include<bits/stdc++.h>
using namespace std;
int n, m, timer;
// Thuât toán tarjan áp dụng cho cạnh cầu
vector<int> adj[1001];
int low[1001], disc[1001];
vector<int> cau;
void Nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
// khong phai dem con cua u
void dfs(int u, int par){
    low[u] = disc[u] = ++timer;
    for(int v : adj[u]){
        if(v == par) continue;
        if(disc[v] == 0){
            dfs(v, u);
            if(par != -1 && low[v] > disc[u]) cau.push_back(u);
            low[u] = min(low[u], low[v]);
        }else{
            low[u] = min(low[u], disc[v]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nhap();
    for(int i = 1; i <= n; i++){
        if(disc[i] == 0){
            dfs(i, -1);
        }
    }   
    for(int x : cau) cout << x << " ";

    return 0;
}