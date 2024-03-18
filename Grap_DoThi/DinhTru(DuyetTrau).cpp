#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> ke[1001];
bool visited[1001];
// Code bang cach duyet trau
// Dinh tru : khi xoa dinh day di thi so thanh phan lien thong cua do thi tang len so voi ban dau
void Nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int x : ke[v]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }
}
int LienThong(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ++cnt;
            bfs(i);
        }
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nhap();
    int cnt1 = LienThong();
    int ans = 0;
    for(int i = 1; i <= n; i++){
        // Nho phai gan lai gia tri cho mang visited
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        int res = LienThong();
        if(res > cnt1) ++ans;
    }
    cout << ans;
    return 0;
}