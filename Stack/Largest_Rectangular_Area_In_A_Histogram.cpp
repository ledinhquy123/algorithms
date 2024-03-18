#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// largest rectangular area in a histogram
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    stack<int> st;
    ll ans = -1e9;
    int i = 0;
    while(i < n){
        if(st.empty() || a[i] >= a[st.top()]){
            st.push(i);
            i++;
        }
        else{
            int top = st.top(); st.pop();
            if(st.empty()) ans = max(ans, 1ll * a[top] * i);
            else ans = max(ans, 1ll * a[top] * (i - st.top() - 1));
        }
    }
    while(!st.empty()){
        int top = st.top(); st.pop();
        if(st.empty()) ans = max(ans, 1ll * a[top] * i);
        else ans = max(ans, 1ll * a[top] * (i - st.top() - 1));
    }
    cout << ans;
    
    return 0;
}