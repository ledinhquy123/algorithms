#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e3 + 1;
int n, m;
vector<int> adj[maxN];
int HC[maxN], degree[maxN];
bool used[maxN];
void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }
    memset(used, false, sizeof(used));
}
bool check(){
    for(int i = 1; i <= n; i++){
        if(degree[i] < n / 2) return false;
    }
    return true;
}
void Hamilton_Cycle(int u, int pos){
    HC[pos] = u;
    used[u] = true;
    if(pos == n){
        for(int v : adj[u]){
            if(v == HC[1]){
                HC[++pos] = v;
                for(int i = 1; i <= pos; i++){
                    cout << HC[i] << " ";
                }
                cout << endl;
            }
        }
        return;
    }
    for(int v : adj[u]){
        if(!used[v]){
            Hamilton_Cycle(v, pos + 1);
            used[v] = false;
        }
    }
    used[u] = false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inp();
    if(check()){
        Hamilton_Cycle(1, 1);
    }else cout << "Khong co chu trinh Hamilton!";
    return 0;
}