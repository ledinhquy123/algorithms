#include<bits/stdc++.h>
using namespace std;
// dsu :: disjoint set union
// ctdt : tim(find), gop(union)
int n, m;
vector<int> adj[1001];
int parent[1001], sz[1001];
void Nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
// gan cho tat ca cac dinh ban dau la cha cua chinh no
void init(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1; // ban đầu đứng độc lập nên sz của mỗi đỉnh là 1 
    }
}
// tim cha cua dinh 
int Find(int u){
    // Cách này sẽ không được tối ưu vì mỗi lần tìm cha phải lần từng bước lại nên sẽ dùng 1 phương pháp nén đường
    while(u != parent[u]){
        u = parent[u];
    }
    return u;
}  
int Find1(int u){
    // Phương pháp nén đường path compression đưa tất cả những đỉnh trên đường đi của đỉnh u về cha của nó có cha cùng với cha của u
    if(u == parent[u]) return u;
    // return parent[u] = Find1(parent[u]);
    else{
        int res = parent[u];
        u = res;
        return res;
    }
}
// Gop 2 dinh
bool Union(int u, int v){
    u = Find1(u);
    v = Find1(v);
    if(u == v) return false; // khi cung cha thi khong the gop 2 nhom
    if(u > v) parent[u] = v;
    else parent[v] = u;
    return true;
}
// Toi uu theo size
// Ham union cx co the check chu trinh
bool Union1(int u, int v){
    u = Find1(u);
    v = Find1(v);
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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    n = 5;
    init();
    Union(1, 2);
    Union(2, 3);
    Union(3, 4);
    Union(4, 5);
    for(int i = 1; i <= n; i++) cout << parent[i] << " ";

    return 0;
}