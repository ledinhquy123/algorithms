#include<bits/stdc++.h>
using namespace std;
// kiểm tra xem 2 đỉnh bất kì có đường đi tới nhau hay không
int n, m;
vector<int> ke[1001];
bool visited[1001];
int tplt[1001];
int cnt;
void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        tplt[v] = cnt;
        for(int x : ke[v]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inp();
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ++cnt;
            bfs(i);
        }
    }
    int Q; cin >> Q;
    while(Q--){
        int u, v; cin >> u >> v;
        if(tplt[u] == tplt[v]) cout << "1\n";
        else cout << "-1\n";
    }

    return 0;
}