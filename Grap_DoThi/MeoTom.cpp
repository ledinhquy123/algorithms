#include<bits/stdc++.h>
using namespace std;
// meo tom an ca
int n, m, cnt; // cnt dem so con ca tren la ma meo co the an
int gian[1001];
vector<int> ke[1001];
bool used[1001];
void Nhap(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> gian[i];
    }
    for(int i = 0; i < n - 1; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(used, false, sizeof(used));
}
void dfs(int u, int dem){
    used[u] = true;
    if(dem > m) return; // so con gian tren duong di lon hon so con gian de bai yeu cau
    if(ke[u].size() == 1 && u != 1) ++cnt;
    // relaxation
    for(int x : ke[u]){
        if(!used[x]){
            if(gian[x]){
                dfs(x, dem + 1); // neu dinh co gian thi tang so lan gap gian
            }else dfs(x, 0);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nhap();
    dfs(1, gian[1]);
    cout << cnt;
    return 0;
}