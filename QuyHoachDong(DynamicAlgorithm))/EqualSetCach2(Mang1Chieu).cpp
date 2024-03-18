#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
using ll = long long;
ll inverse(ll a, ll b, ll m){
    ll res = 1;
    a %= m;
    while(b){
        if(b & 1){
            res *= a;
            res %= m;
        }
        a *= a;
        a %= m;
        b >>= 1;
    }
    return res;
}
int main(){
    int n; cin >> n;
    ll sum = 0;
    for(int i = 1; i <= n; i++) sum += i;
    if(sum % 2 == 1){
        cout << 0;
        return 0;
    }
    sum /= 2;
    int dp[sum + 1] = {0};
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = sum; j >= 1; j--){
            if(j >= i) dp[j] += dp[j - i];
            dp[j] %= mod;
        }
    }
    cout << (1ll * dp[sum] * inverse(2, mod - 2, mod)) % mod;
    return 0;
}