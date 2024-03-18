#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// dfs : depth first search
vector<int> ke[1001];
bool visited[1001];
int n, m, s;
void Nhap(){
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        sort(ke[i].begin(), ke[i].end());
    }
    memset(visited, false, sizeof(visited));
}
void dfs(int u){
    cout << u << " ";
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
    Nhap();
    dfs(s);

    return 0;
}