#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a, b, n;
bool check(ll x){
    ll k = x / a;
    ll l = x / b;
    return k * l >= n;
}
int main(){
    cin >> a >> b >> n;
    ll left = 0, right = 1ll * max(a, b) * n, ans = 0;
    while(left <= right){
        ll m = (left + right) / 2;
        if(check(m)){
            ans = m;
            right = m - 1;
        }else left = m + 1;
    }
    cout << ans;
    return 0;
}