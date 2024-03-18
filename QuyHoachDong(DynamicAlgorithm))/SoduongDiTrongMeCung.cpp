#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
using ll = long long;
ll dp[1001][1001];
int main(){
   int n; cin >> n;
   char a[n + 1][n + 1];
   for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++) cin >> a[i][j];
   }
   dp[1][0] = dp[0][1] = 1;
   for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
         if(a[i][j] == '.'){
            if(i == 1) dp[i][j] = dp[i][j - 1];
            else if(j == 1) dp[i][j] = dp[i - 1][j];
            else{
               dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            }
            dp[i][j] %= mod;
         }else dp[i][j] = 0;
      }
   }
   cout << dp[n][n];
   return 0;
}