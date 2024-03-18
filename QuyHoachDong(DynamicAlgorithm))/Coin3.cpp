#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
// tinh so cach rieng biet khong xet den thu tu 
int main(){
    int n, x; cin >> n >> x;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int dp[x + 1] = {0};
    dp[0] = 1;  
    for(int i = 0; i < n; i++){
        for(int j = a[i]; j <= x; j++){
            dp[j] += dp[j - a[i]];
            dp[j] %= mod;
        }
    }
    cout << dp[x];
    return 0;
}