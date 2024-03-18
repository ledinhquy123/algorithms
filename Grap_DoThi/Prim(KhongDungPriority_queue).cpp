#include<bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 1;
struct edge{
    int x, y, w;
};
int n, m;
bool used[maxN];
vector<pair<int, int>> adj[maxN];
void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    memset(used, false, sizeof(used)); // danh dau tat ca cac dinh ban dau deu thuoc tap v
}
void Prim(int u){
    long long d = 0;
    used[u] = true;  // xoa u khoi tap v va day vao tap v(MST)
    vector<edge> MST;
    while(MST.size() < (n - 1)){
        // tim dinh e ngan nhat co 1 dinh thuoc v, 1 dinh thuoc v(MST)
        int min_w = 1e9, X, Y; // x, y la 2 dinh cua canh e
        for(int i = 1; i <= n; i++){
            if(used[i]){
                for(auto v : adj[i]){
                    int j = v.first, trongSo = v.second;
                    if(!used[j]){
                        if(trongSo < min_w){
                            min_w = trongSo;
                            X = i; Y = j;
                        }
                    }
                }
            }
        }
        d += min_w;
        MST.push_back({X, Y, min_w});
        // y thuoc v, x thuoc v(MST)
        used[Y] = true;
    }
    if(d) cout << d << endl;
    else cout << "IMPOSSIBLE\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inp();
    Prim(1);

    return 0;
}
// 5 6
// 1 2 3
// 2 3 5
// 2 4 2
// 3 4 8
// 5 1 7
// 5 4 4

// 6 9
// 1 2 9
// 1 3 4
// 2 3 1
// 2 4 6
// 2 5 3
// 3 5 2
// 4 5 3
// 4 6 10
// 5 6 8