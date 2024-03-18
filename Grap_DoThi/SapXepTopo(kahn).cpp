#include<bits/stdc++.h>
using namespace std;
// Sắp xếp topo bằng thuật toán kahn : xóa dần đỉnh bằng bfs
// Duy trì thêm bán bậc vào deg-
int n, m;
vector<int> ke[1001];
int degree[1001]; // luu cac ban bac vao
vector<int> topo;
void Nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        degree[y]++;
    }
}
void kahn(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(degree[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int v = q.front(); q.pop();
        topo.push_back(v);
        for(int x : ke[v]){
            degree[x]--;
            if(degree[x] == 0) q.push(x);
        }
    }
    // Có thể dùng check chu trình trên đồ thị có hướng
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nhap();
    kahn();
    for(int x : topo) cout << x << " ";

    return 0;
}