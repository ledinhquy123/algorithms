#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
using ll = long long;
//Dem so cach chia mang thanh 2 tap hop vo tong bang nhau
int dp[501][100001];
int main(){
    int n; cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++) sum += i;
    if(sum % 2 != 0){
        cout << 0;
        return 0;
    }
    sum /= 2;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= i) dp[i][j] += dp[i - 1][j - i];
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][sum];
    return 0;
}