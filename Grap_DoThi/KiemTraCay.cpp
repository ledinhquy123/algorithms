#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> ke[1001];
bool visited[1001];
int parent[1001];
// Cay la do thi vo huong lien thong va khong co chu trinh
void Nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
// Kiem tra chu trinh
bool dfs(int u){
    visited[u] = true;
    for(int x : ke[u]){
        // parent[x] = u;
        if(!visited[x]){
            parent[x] = u;
            if(dfs(x)) return true;
        }else if(x != parent[u]) return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nhap();
    // Neu ton tai chu trinh thi khong phai cay
    if(dfs(1)){
        cout << "0";
        return 0;
    }
    // kiem tra so thanh phan lien thong
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cout << "0";
            return 0;
       }
    }
    cout << "1";
    return 0;
}