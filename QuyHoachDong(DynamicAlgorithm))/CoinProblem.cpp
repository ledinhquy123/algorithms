#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
    int n, s; cin >> n >> s;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int dp[s + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= s; i++){
        dp[i] = 1e9;
        for(int j = 0; j < n; j++){
            if(i >= a[j]) dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }
    }
    // for(int i = 0; i <= s; i++) cout << dp[i] << " ";
    if(dp[s] != 1e9) cout << dp[s];
    else cout << -1;

    return 0;
}