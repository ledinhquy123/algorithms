#include<bits/stdc++.h>
using namespace std;
int n, m, cnt;
vector<int> ke[1001];
bool visited[1001];
vector<pair<int, int>> luu;
// Cạnh cầu : Khi bỏ cạnh này thì số lượng tp liên thông của đồ thị tăng lên, tương tự đỉnh trụ
void Nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
        // dùng để lưu các cạnh
        luu.push_back({x, y});
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
int LienThong(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ++cnt;
            dfs(i);
        }
    }
    return cnt;
}
void Reset(){
    for(int i = 1; i <= n; i++){
        // Xóa cạnh giữa các đỉnh
        ke[i].clear();
    }
    memset(visited, false, sizeof(visited));
}
void CanhCau(int canh, int cnt1){
    for(int i = 0; i < m; i++){
        if(i != canh){
            // Khác cạnh cần xóa thì chèn vào vector 'kề' đê tính những cạnh còn lại sau khi xoá cạnh
            ke[luu[i].first].push_back(luu[i].second);
            ke[luu[i].second].push_back(luu[i].first);
        }
    }
    int ans = LienThong(); 
    if(ans > cnt1) ++cnt;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nhap();
    int cnt1 = LienThong();
    // Duyệt các cạnh
    for(int i = 0; i < m; i++){
        Reset();
        CanhCau(i, cnt1);
    }   
    cout << cnt;

    return 0;
}