#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n, k; cin >> n >> k;
    int a[n] = {0};
    for(int i = 1; i <= n; i++) cin >> a[i];
    int dp[n + 1];
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = -1e9;
        for(int j = 1; j <= k; j++){
            if(i >= j) dp[i] = max(dp[i], dp[i - j] + a[i]);
        }
    }
    cout << *max_element(dp + 1, dp + n + 1);
    return 0;
}