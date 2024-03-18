#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    string s; cin >> s;
    s = "@" + s;
    int n = s.length();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    int res = -1e9;
    for(int i = 1; i < n; i++) dp[i][i] = 1;
    for(int len = 2; len < n; len++){
        for(int i = 1; i < n - len + 1; i++){
            int j = i + len - 1;
            if(len == 2 && s[i] == s[j]) dp[i][j] = 2;
            else{
                if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[1][n - 1];
    return 0;
}