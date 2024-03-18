#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7, maxN = (int)(102);
int n, m, a[maxN][maxN];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<int> v[maxN];
void dfs(int i, int j){
    a[i][j] = 0;
    v[i].push_back(j);
    for(int k = 0; k < 8; k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1]){
            dfs(i1, j1);
        }
    }
}
bool check(){
    int res[maxN][maxN];
    memset(res, 0, sizeof(res));
    int x1 = maxN, y1 = maxN, x2 = 0, y2 = 0;
    for(int i = 0; i < maxN; i++){
        if(!v[i].empty()){
            for(int j : v[i]){
                x1 = min(x1, i);
                y1 = min(y1, j);
                x2 = max(x2, i);
                y2 = max(y2, j);
                res[i][j] = 1;
            }
        }
    }
    for(int i = x1; i <= x2; i++){
        for(int j = y1; j <= y2; j++){
            if(res[i][j] == 0) return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 1){
                dfs(i, j);
                if(check()) cnt++;
                for(int k = 0; k < maxN; k++){
                    v[k].clear();
                }
            }
        }
    }
    cout << cnt;
    
    return 0;
}