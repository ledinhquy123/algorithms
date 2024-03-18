#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a[505][505];
int n, m;
ll Histogram(int i){
    ll ans = -1e9;
    stack<int> st;
    int j = 0;
    while(j < m){
        if(st.empty() || a[i][j] >= a[i][st.top()]){
            st.push(j);
            ++j;
        }
        else{
            int pos = st.top(); st.pop();
            if(st.empty()) ans = max(ans, 1ll * j * a[i][pos]);
            else ans = max(ans, 1ll * (j - st.top() - 1) * a[i][pos]);
        }
    }
    while(!st.empty()){
        int pos = st.top(); st.pop();
        if(st.empty()) ans = max(ans, 1ll * j * a[i][pos]);
        else ans = max(ans, 1ll * (j - st.top() - 1) * a[i][pos]);
    }
    return ans;
}   
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    ll res = -1e9;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j]) a[i][j] = a[i - 1][j] + 1;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            res = max(res, Histogram(i));
        }
    }
    cout << res;
    

    return 0;
}