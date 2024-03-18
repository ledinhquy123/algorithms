#include<bits/stdc++.h>
using namespace std;
// Đồ thị 2 phía : là đồ thị mà chia làm 2 tập trong đó các đỉnh thuộc 1 tập thì không có đường nối tới nhau
// Các đỉnh trong 2 tập sẽ có màu khác nhau (đỏ, xanh)
int n, m;
int color[1001];
vector<int> ke[1001];
void Nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}
// Tìm kiếm theo chiều sâu
bool dfs(int u, int par){
    // Lưu color[0] = 2 thì color[1] = 3 - color[0] = 1, color[2] = 3 - color[1] = 3 - 1 = 2
    color[u] = 3 - color[par];
    for(int x : ke[u]){
        if(color[x] == 0){
            if(!dfs(x, u)) return false;
        }else if(color[x] == color[u]) return false;
    }
    return true;
}
// Tìm kiếm theo chiều rộng
bool bfs(int u, int par){
    queue<int> q;
    color[u] = 3 - color[par];
    q.push(u);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int x : ke[v]){
            if(color[x]){
                if(color[x] == color[v]) return false;
            }else{
                color[x] = 3 - color[v];
                q.push(x);
            }
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nhap();
    color[0] = 2;
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            if(!bfs(i, 0)){
                cout << "NO";
                return 0;
            }
        }
    }   
    cout << "YES";
    return 0;
}