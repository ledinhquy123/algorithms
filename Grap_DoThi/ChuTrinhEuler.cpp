#include<bits/stdc++.h>
using namespace std;
const int maxN = (int)(1e3 + 1);
int n, m;
vector<int> EC;
set<int> adj[maxN];
int degree[maxN];
void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        degree[x]++;
        degree[y]++;
    }
}
void euler(int u){
    stack<int> st;
    st.push(u);
    while(!st.empty()){
        int v = st.top();
        if(!adj[v].empty()){
            int x = *adj[v].begin();
            st.push(x);
            adj[v].erase(x);
            adj[x].erase(v);
        }else{
            st.pop();
            EC.push_back(v);
        }
    }
    bool ok = true;
    for(int i = 1; i <= n; i++){
        if(degree[i] % 2 != 0){
            ok = false;
            break;
        }
    }
    if(ok){
        for(int it : EC) cout << it << " ";
    }else cout << "Khong co chu trinh euler!";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inp();
    euler(3);

    return 0;
}