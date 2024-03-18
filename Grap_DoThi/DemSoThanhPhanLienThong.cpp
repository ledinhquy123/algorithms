#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
vector<int> ke[1001];
bool visited[1001];
void Nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, 0, sizeof(visited));
}
void dfs(int u){
    visited[u] = true;
    for(auto x : ke[u]){
        if(!visited[x]){
            dfs(x);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int dem = 0;
    Nhap();
    // dfs(1);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ++dem;
            dfs(i);
        }
    }
    cout << dem;
    return 0;
}