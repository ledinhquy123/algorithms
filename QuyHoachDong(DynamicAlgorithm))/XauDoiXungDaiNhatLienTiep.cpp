#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
using ll = long long;
int main(){
    string s; cin >> s;
    s = "@" + s;
    int n = s.length();
    int dp[n][n];
    string res = "";
    // dp[i][j] : 1 xau bat dau tu chi so i ket thuc tai chi so j thi i <= j
    memset(dp, 0, sizeof(dp));
    // xay dung xau co do dai la 1 (luon doi xung)
    for(int i = 1; i < n; i++) dp[i][i] = 1;
    int ans = -1e9;
    for(int len = 2; len < n; len++){
        for(int i = 1; i < n - len + 1; i++){
            // xay dung xau co do dai la 2
            int j = i + len - 1;
            if(len == 2 && (s[i] == s[j])) dp[i][j] = 1;
            else{
                if(s[i] == s[j] && dp[i + 1][j - 1]) dp[i][j] = 1;
            }
            // neu la 1 xau doi xung thi moi cap nhat
            //Truy vet
            if(dp[i][j] && ans < len){
                ans = len;
                res = s.substr(i, len);
            }
        }
    }
    cout << ans << endl;
    cout << res;
    return 0;   
}