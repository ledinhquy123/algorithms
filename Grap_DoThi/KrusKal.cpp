#include<bits/stdc++.h>
using namespace std;
// Ứng dụng là tìm chi phí nhỏ nhất thường dùng trong mạng máy tính,..
int n, m;
vector<int> adj[1001];
int parent[1001], sz[1001];
void init(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}
int Find(int u){
    if(u == parent[u]) return u;
    else{
        // return parent[u] = Find(parent[u]);
        int res = parent[u];
        u = res;
        return res;
    }
}
// check chu trinh
bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(sz[u] < sz[v]){
        parent[u] = v;
        sz[v] += sz[u];
    }else{
        parent[v] = u;      
        sz[u] += sz[v];
    }
    return true;
}
struct edge{
    int x, y, w;
};
vector<edge> canh;
void Nhap(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        canh.push_back({x, y, w});
    }
    init(); // cap nhat co so cho disjointset union
}
void kruskal(){
    // b1: sap xep cac dinh tang dan theo trong so
    sort(canh.begin(), canh.end(), [](edge x, edge y)->bool{
        return x.w < y.w;
    });
    int d = 0; // luu khoang cach(trong so)
    vector<edge> MST; // luu cay khung
    // duyet cac canh trong do thi
    for(int i = 0; i < m; i++){
        if(MST.size() == n - 1) break; // khi nay da la 1 cay
        int u = canh[i].x, v = canh[i].y;
        if(Union(u, v)){
            MST.push_back(canh[i]);
            d += canh[i].w;
        }
    }
    cout << d << endl;
    for(auto x : MST){
        cout << x.x << ' ' << x.y << " " << x.w << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Nhap();
    kruskal();

    return 0;
}