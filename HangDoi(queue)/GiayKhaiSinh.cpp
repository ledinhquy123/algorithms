#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// dung do thi de lam
map<string, int> mp; // chuyen doi ten thanh dinh
map<int, string> rev_mp; //  chuyen doi dinh thanh ten
vector<pair<int, int>> adj[101];
int n, m;
int res[101]; // luu tuoi
void Nhap(){
    mp.clear();
    for(int i = 1; i <= 100; i++){
        adj[i].clear();
    }
    n = 0; // luu so dinh
    cin >> m;
    for(int i = 0; i < m; i++){
        string x, y; cin >> x >> y;
        int w; cin >> w;
        if(mp.count(x) == 0){
            mp[x] = ++n;
            rev_mp[n] = x;
        }
        if(mp.count(y) == 0){
            mp[y] = ++n;
            rev_mp[n] = y;
        }
        adj[mp[x]].push_back({mp[y], w}); // dung do thi co huong
    }
}
void bfs(int u){
    res[mp["Ted"]] = 100;
    queue<int> q;
    q.push(mp["Ted"]);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto x : adj[v]){
            int d = x.first; int w = x.second;
            res[d] = res[v] - w;
            q.push(d);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    for(int k = 1; k <= t; k++){
        Nhap();
        bfs(mp["Ted"]);
        vector<pair<string, int>> v;
        for(int i = 1; i <= n; i++){
            v.push_back({rev_mp[i], res[i]});
        }
        sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b)->bool{
            return a.second > b.second;
        });
        cout << "DATASET " << k << endl;
        for(int i = 1; i < v.size(); i++){
            cout << v[i].first << " " << v[i].second << endl;
        }
    }

    return 0;
}