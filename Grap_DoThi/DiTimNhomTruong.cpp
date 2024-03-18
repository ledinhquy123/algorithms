#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
vector<int> ke[1001];
bool visited[1001];
// di tim nhom truong
void Nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
vector<int> ans; // luu cac dinh ke cua dinh u
void dfs(int u){
    visited[u] = true;
    ans.push_back(u);
    for(int x : ke[u]){
        if(!visited[x]){
            dfs(x);
        }
    }
}
vector<int> res; // luu cac dinh co lien thong nhieu nhat
void solve(){
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            int max_val = -1e9, gt = -1e9;
            for(int x : ans){
                int tmp = ke[x].size();
                if(tmp > max_val){
                    max_val = tmp;
                    gt = x;
                }else if(tmp == max_val){
                    if(gt > x) gt = x;
                }
            }
            res.push_back(gt);
            ans.clear();
        }
    }
    sort(res.begin(), res.end());
    for(int x : res) cout << x << " ";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nhap();
    solve();

    return 0;
}