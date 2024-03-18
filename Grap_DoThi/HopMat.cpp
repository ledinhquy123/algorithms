#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, k;
vector<int> ke[10001];
map<int, int> mp;
bool visited[10001];
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    mp[u]++;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int x : ke[v]){
            if(!visited[x]){
                visited[x] = true;
                mp[x]++;
                q.push(x);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n >> m;
    int arr[k];
    for(int &x : arr) cin >> x;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
    }
    for(int x : arr){
        memset(visited, false, sizeof(visited));
        bfs(x);
    }
    ll ans = 0;
    for(auto x : mp){
        if(x.second == k) ++ans;
    }
    cout << ans;

    return 0;
}