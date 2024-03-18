#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> ke[1001];
int color[1001];
// 0 - mua trang : chua tham
// 1 - mau xam : tham chua xong, chua them het cac dinh ke
// 2 - mau den : da tham xong
void Nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
    }
    memset(color, 0, sizeof(color));
}
// Dung thuat toan dfs theo chieu sau
bool dfs(int u){
    color[u] = 1; // mau xam
    for(int x : ke[u]){
        if(color[x] == 0){ // mau trang
            if(dfs(x)) return true;
        }else if(color[x] == 1) return true;
    }
    color[u] = 2; // mau den
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nhap();
    for(int i = 1; i <= n; i++){
        if(dfs(i)){
            cout << "1";
            return 0;
        }
    }
    cout << "0";
    return 0;
}
// Neu dung bfs theo chiue rong thi pahi dung thuat toan kahn - xoa dan dinh