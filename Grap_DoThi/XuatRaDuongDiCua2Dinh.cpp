#include<bits/stdc++.h>
using namespace std;
int n, m, s, t;
vector<int> ke[1001];
bool visited[1001];
int parent[1001]; // luu dinh cha cua cac dinh 
void inp(){
    cin >> n >> m >> s >> t;
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
// tim kiem theo chieu sau
void dfs(int u){
    visited[u] = true;
    for(int x : ke[u]){
        if(!visited[x]){
            visited[x] = true;
            parent[x] = u;
            dfs(x);
        }
    }
}
// tim kiem theo chieu rong
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto x : ke[v]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
                parent[x] = v;
            }
        }
    }
}
void DuongDi(){
    dfs(s);
    if(visited[t]){
        // di nguoc lai tu t ve s xong lat nguoc vector
        vector<int> res;
        while(t != s){
            res.push_back(t);
            t = parent[t];
        }
        res.push_back(s);
        reverse(res.begin(), res.end());
        for(auto x : res) cout << x << " ";
    }else cout << -1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inp();
    DuongDi();
    return 0;
}