#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// Sắp xếp topo bằng dfs base
// Tồn tại sắp xếp topo khi đồ thị có hướng và không có chu trình
// Từ đỉnh a -> b : thì thứ tự của a luôn đứng trước b trong sắp xếp topo
// Trong 1 đồ thị thì có nhiều sắp xếp topo thỏa mãn
int n, m;
vector<int> ke[1001];
bool visited[1001];
vector<int> topo;
void Nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
}
void dfs(int u){
    visited[u] = true;
    for(int x : ke[u]){
        if(!visited[x]){
            dfs(x);
        }
    }
    // duyet xong co mau den
    topo.push_back(u);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nhap();
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    reverse(topo.begin(), topo.end());
    for(int x : topo) cout << x << " ";

    return 0;
}