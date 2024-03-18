#include<bits/stdc++.h>
using namespace std;
int n, m; 
char a[1001][1001];
int pre[1001][1001];
int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};
string s = "LUDR";
bool bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    a[i][j] = '#';
    while(!q.empty()){
        auto it = q.front(); q.pop();
        int i = it.first, j = it.second;
        for(int k = 0; k < 4; k++){
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1] != '#'){
                pre[i1][j1] = k;
                if(a[i1][j1] == 'B') return true;
                a[i1][j1] = '#';
                q.push({i1, j1});
            }
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    pair<int, int> start, end;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'A'){
                start.first = i;
                start.second = j;
            }
            if(a[i][j] == 'B'){
                end.first = i;
                end.second = j;
            }
        }
    }
    if(bfs(start.first, start.second)){
        string res = "";
        int i = end.first, j = end.second;
        while(!(start.first == i && start.second == j)){
            int k = pre[i][j];
            res += s[k];
            i = i - dx[k];
            j = j - dy[k];
        }
        reverse(res.begin(), res.end());
        cout << "YES\n";
        cout << res.size() << endl;
        cout << res << endl;
    }else cout << "NO\n";
 
    return 0;
}