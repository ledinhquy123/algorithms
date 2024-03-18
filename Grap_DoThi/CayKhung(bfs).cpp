#include<bits/stdc++.h>
using namespace std;
// Cây khung bằng bfs
int n, m, s;
vector<int> ke[1001];
bool visited[1001];
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
vector<string> CayKhung;
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int x : ke[v]){
            if(!visited[x]){
                visited[x] = true;
                string res = "";
                res = to_string(v) + "->" + to_string(x);
                q.push(x);
                CayKhung.push_back(res);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    Nhap();
    bfs(s);
    for(auto x : CayKhung) cout << x << endl;

    return 0;
}