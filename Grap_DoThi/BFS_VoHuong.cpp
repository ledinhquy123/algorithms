#include<bits/stdc++.h>
using namespace std;
int n, m, s;
vector<int> ke[1001];
bool visited[1001];
void Inp(){
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
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int v = q.front();
        cout << v << " ";
        q.pop();
        // duyet
        for(auto x : ke[v]){
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
    Inp();
    bfs(s);

    return 0;
}