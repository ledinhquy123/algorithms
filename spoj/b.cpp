#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000001];
bool used[1000001];
int n, m, ans;

void inp(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ans = 0;
    memset(used, false, sizeof(used));
}

void solve(int u, int s){
    used[u] = true;
    if(u == s){
        ++ans;
        return;
    }

    for(int v : adj[u]){
        if(!used[v]){
            solve(v, s);
            used[v] = false;
        }
    }
    used[u] = false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    inp();
    solve(1, 4);
    cout << ans;
    
    return 0;
}
