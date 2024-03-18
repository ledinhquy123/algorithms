#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> ke[1001];
int parent[1001];
bool visited[1001];
// Chi ap dung cho VO HUONG khong duoc dung cho CO HUONG
void Nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
// Tim kiem theo chieu sau
bool dfs(int u){
    visited[u] = true;
    for(int x : ke[u]){
        if(!visited[x]){
            visited[x] = true;
            parent[x] = u;
            if(dfs(x)) return true;
        }else if(x != parent[u]) return true;
    }
    return false;
}
// Tim kiem theo chieu rong
bool bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int x : ke[v]){
            if(!visited[x]){
                visited[x] = true;
                parent[x] = v;
                q.push(x);
            }else if(x != parent[v]) return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nhap();
    // Phai lan luot kiem tra het cac dinh 
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            if(bfs(i)){
                cout << "1";
                return 0;
            }
        }
    }
    cout << "0";
    return 0;
}