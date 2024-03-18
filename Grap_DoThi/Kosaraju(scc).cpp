#include<bits/stdc++.h>
using namespace std;
// Thuat toan kosaraju
int n, m;
bool visited[1001];
vector<int> adj[1001];
vector<int> t_adj[1001]; // do thi nguoc tranpose grap cau do thi ban dau
void Nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        t_adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
stack<int> st;
void dfs(int u){
    visited[u] = true;
    for(int x : adj[u]){
        if(!visited[x]){
            dfs(x);
        }
    }
    st.push(u);
}
void t_dfs(int u){
    cout << u << ' ';
    visited[u] = true;
    for(int x : t_adj[u]){
        if(!visited[x]){
            t_dfs(x);
        }
    }
}
// scc :: cac thanh phan lien thong manh
void scc(){
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    memset(visited, false, sizeof(visited));
    while(!st.empty()){
        int u = st.top(); st.pop();
        if(!visited[u]){
            t_dfs(u);
            cout << endl;
        }
    }
}
// 1 do thi co 1 thanh phan lien thong manh goi la do ti lien thong manh
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nhap();
    scc();

    return 0;
}