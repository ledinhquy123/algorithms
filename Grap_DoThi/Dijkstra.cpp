#include<bits/stdc++.h>
using namespace std;
// Dijkstra : tìm đường đi ngắn nhất
// Từ 1 đỉnh đến mọi đỉnh trong đồ thị
// Áp dụng cả vô hướng, có hướng
// Có trọng số không âm
int n, m, s;
vector<pair<int, int>> adj[1001];
void Nhap(){
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        // adj[y].push_back({x, w});
    }
}
void Dijkstra(int s){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<bool> used(n + 1, false);
    vector<int> d(n + 1, 1e9);
    d[s] = 0;
    q.push({0, s});
    while(!q.empty()){
        // lay ra duoc dinh a co duong di toi s la ngan nhat
        pair<int, int> top = q.top(); q.pop();
        if(used[top.second]) continue;
        used[top.second] = true;
        int u = top.second;
        // relaxation : duyet cac dinh ke
        for(auto it : adj[u]){
            // trong adj first : luu din h, second : luu khoang cach
            int v = it.first, w = it.second;
            if(d[v] > d[u] + w){ // li do luu 1e9
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    // in ra khoang cach tu dinh s toi cac dinh trong do thi
    for(int i = 1; i <= n; i++){
        cout << d[i] << " ";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nhap();
    Dijkstra(s);

    return 0;
}