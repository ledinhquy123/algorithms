#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
using ll = long long;
int main(){
    string s; cin >> s;
    int n = s.length();
    s = "@" + s;
    ll dp[n + 1] = {0};
    for(int i = 1; i <= n; i++){
        dp[i] = 1ll * dp[i - 1] * 10 + 1ll * i * (s[i] - '0');
    }
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        sum += dp[i];
    }
    cout << sum;
    return 0;
}