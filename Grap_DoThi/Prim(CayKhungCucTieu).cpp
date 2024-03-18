#include<bits/stdc++.h>
using namespace std;
// Prim : sẽ tạo 2 tập hợp v vs vh (cây khung cực tiểu)
// Mỗi bước sẽ chọn 1 đỉnh thuộc v và 1 dỉnh thuộc vh sao cho khoảng cách từ v đến vh nhỏ nhất rồi thêm dỉnh từ vh vào tập v
int n, m;
vector<pair<int, int>> adj[1001];
bool used[1001];
int parent[1001], d[1001];
struct edge{
    int x, y, w;
};
void Nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    memset(used, false, sizeof(used));
    for(int i = 1; i <= n; i++){
        d[i] = 1e9;
    }
}
void Prim(int u){
    // dung 1 hang doi uu tien min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<edge> ck;
    int res = 0;
    q.push({0, u}); // q.first : luu trong so, q.second : luu dinh
    while(!q.empty()){
        pair<int, int> top = q.top(); q.pop();
        if(used[top.second]) continue;
        res += top.first;
        used[top.second] = true;
        if(top.second != u) ck.push_back({top.second, parent[top.second], top.first});
        for(auto it : adj[top.second]){
            if(!used[it.first] && it.second < d[it.first]){
                q.push({it.second, it.first});
                d[it.first] = it.second;
                parent[it.first] = top.second;
            }
        }
    } 
    cout << res << endl;
    for(auto it : ck){
        cout << it.x << " " << it.y << " " << it.w << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nhap();
    Prim(1);

    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long;
// int n, m;
// vector<pair<int, int>> adj[100001];
// bool used[100001];
// void Nhap(){
//     cin >> n >> m;
//     for(int i = 0; i < m; i++){
//         int x, y, w; cin >> x >> y >> w;
//         adj[x].push_back({y, w});
//         adj[y].push_back({x, w});
//     }
//     memset(used, false, sizeof(used));
// }
// void Prim(int u){
//     // dung 1 hang doi uu tien min heap
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
//     ll res = 0;
//     int cnt = 0;
//     q.push({0, u}); // q.first : luu trong so, q.second : luu dinh
//     while(!q.empty()){
//         pair<int, int> top = q.top(); q.pop();
//         if(used[top.second]) continue;
//         res += top.first;
//         ++cnt;
//         used[top.second] = true;
//         for(auto it : adj[top.second]){
//             if(!used[it.first]){
//                 q.push({it.second, it.first});
//             }
//         }
//     } 
//     if(cnt >= n - 1) cout << res;
//     else cout << "IMPOSSIBLE";
// }
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     Nhap();
//     Prim(1);
//     return 0;
// }