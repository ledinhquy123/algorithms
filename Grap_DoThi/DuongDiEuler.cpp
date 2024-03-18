#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 1e3 + 1;
int n, m;
set<int> adj[maxN];
vector<int> EC;
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
void DuongDiEuler(int u){
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
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(degree[i] % 2 != 0){
            cnt++;
        }
    }
    if(cnt == 0 || cnt == 2){
        reverse(EC.begin(), EC.end());
        for(int it : EC) cout << it << " ";
    }else cout << "Khong co duong di euler!";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inp();
    for(int i = 1; i <= n; i++){
        if(degree[i] % 2 != 0){
            DuongDiEuler(i);
            break;
        }
    }

    return 0;
}
// 6 6
// 1 2
// 2 3
// 2 5
// 2 6
// 3 4
// 5 6