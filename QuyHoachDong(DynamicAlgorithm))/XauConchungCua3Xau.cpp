#include<bits/stdc++.h>
using namespace std;
int main(){
    string x, y, z; cin >> x >> y >> z;
    x = "@" + x, y = "@" + y, z = "@" + z;
    int n = x.length(), m = y.length(), k = z.length();
    int dp[n][m][k];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            for(int h = 1; h < k; h++){
                if(x[i] == y[j] && y[j] == z[h]){
                    dp[i][j][h] = dp[i - 1][j - 1][h - 1] + 1;
                }else dp[i][j][h] = max({dp[i - 1][j][h], dp[i][j - 1][h], dp[i][j][h - 1]});
            }
        }
    }
    cout << dp[n - 1][m - 1][k - 1];
    return 0;
}