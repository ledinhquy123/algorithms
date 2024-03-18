#include<bits/stdc++.h>
using namespace std;
// Cây khung dfs
int n, m, s;
vector<int> ke[1001];
bool visited[1001];
vector<string> CayKhung;
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
    visited[u] = true;
    for(int x : ke[u]){
        if(!visited[x]){
            string res = "";
            res = to_string(u) + "->" + to_string(x);
            CayKhung.push_back(res);
            dfs(x);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nhap();
    dfs(s);
    for(auto x : CayKhung) cout << x << endl;

    return 0;
}