#include<bits/stdc++.h>
using namespace std;
// Thuật toán tarjan :  chủ yếu kiểm tra scc, đỉnh trụ, cạnh cầu 
// disc[i] : lưu thời gian bắt đầu thăm đỉnh i
// low[i] : lưu thời gian thăm nhỏ nhất của tất cả các tổ tiên trừ cha trực tiếp
// Nếu low[v] >= disc[u] thì có nghĩa muốn thăm đỉnh v thì bắt buộc phải đi qua đỉnh u => u là đỉnh trụ
// Một đỉnh là gốc bắt đầu duyệt dfs và có ít nhất là 2 con thì sẽ là đỉnh trụ
int n, m, timer;
vector<int> adj[1001];
vector<int> tru;
int low[1001], disc[1001];
void Nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
int dfs(int u, int par){
    disc[u] = low[u] = ++timer;
    int cnt = 0; // dem so con cua dinh u
    for(int v : adj[u]){
        if(v == par) continue; // dinh v la cha truc tiep cua dinh u thi bo qua
        if(disc[v] == 0){ // chua duoc tham
            dfs(v, u);
            ++cnt;
            // kiem tra u co phai dinh tru khong?
            if(par != -1 && low[v] >= disc[u]){
                // la 1 dinh tru
                tru.push_back(u);
            }
            low[u] = min(low[u], low[v]);
        }else{
            low[u] = min(low[u], disc[v]);
        }
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nhap();
    for(int i = 1; i <= n; i++){
        if(disc[i] == 0){
            int dem = dfs(i, -1);
            if(dem >= 2) tru.push_back(i);
        }
    }
    cout << tru.size() << endl;
    for(int x : tru) cout << x << ' ';

    return 0;
}
// KHÓ HIỂU QUÁ !!!!