#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> ke[1001];
bool visited[1001];
// Đồ thị liên thông mạnh 
// Tất cả các đỉnh đều có đường đi tới nhau
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
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nhap();
    for(int i = 1; i <= n; i++){
        memset(visited, false, sizeof(visited));
        dfs(i);
        for(int j = 1; j <= n; j++){
            if(!visited[j]){
                cout << "0";
                return 0;
            }
        }
    }
    cout << "1";
    return 0;
}