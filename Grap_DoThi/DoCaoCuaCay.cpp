#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> ke[1001];
int heigh[1001];
bool visited[1001];
// 1 cay luon co n dinh va n - 1 canh
void dfs(int u, int par){
    visited[u] = true;
    heigh[u] = heigh[par] + 1;
    for(int x : ke[u]){
        if(!visited[x]){
            dfs(x, u);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    heigh[0] = -1;
    dfs(1, 0);
    for(int i = 1; i <= n; i++){
        cout << heigh[i] << " ";
    }
    return 0;
}