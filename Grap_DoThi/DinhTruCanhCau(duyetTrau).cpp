#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 1;
int n, m;
bool used[maxn];
vector<int> adj[maxn];
vector<pair<int, int>> dscanh;
void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        dscanh.push_back({x, y});
    }
}
void dfs(int u){
    used[u] = true;
    for(int v : adj[u]){
        if(!used[v]) dfs(v);
    }
}
void dinhTru(){
    int ans = 0, tplt = 0;
    memset(used, false, sizeof(used));
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            tplt++;
            dfs(i);
        }
    }   
    // memset(used, false, sizeof(used));
    for(int i = 1; i <= n; i++){
        memset(used, false, sizeof(used));
        used[i] = true;
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(!used[j]){
                cnt++;
                dfs(j);
            }
        }
        if(cnt > tplt){
            ++ans; 
        }
    }
    cout << ans << endl;
}
// thu hien duyet do thi nhung bo qua canh (x, y)
void dfs2(int u, int x, int y){
    used[u] = true;
    for(int v : adj[u]){
        if((u == x && v == y) || (u == y && v == x)) continue;
        if(!used[v]) dfs2(v, x, y);
    }
}

void canhCau(){
    int ans, tplt = 0;
    memset(used, false, sizeof(used));
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            tplt++;
            dfs(i);
        }
    }
    for(auto i : dscanh){
        int x = i.first, y = i.second, cnt = 0;
        memset(used, false, sizeof(used));
        for(int j = 1; j <= n; j++){
            if(!used[j]){
                cnt++;
                dfs2(j, x, y);
            }
        }
        if(cnt > tplt) ++ans;
    }
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inp();
    canhCau();

    return 0;
}