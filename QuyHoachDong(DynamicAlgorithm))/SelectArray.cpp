#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
using ll = long long;
// dp[i][i] : la so cach chon tai vi tri i co gia tri la i
ll dp[100001][101];
// select array
int main(){
    int n, m; cin >> n >> m;
    int a[n + 1];
    for(int i = 0; i < n; i++) cin >> a[i];
    // Xay dung co so quy hoach dong
    if(a[0]){
        dp[0][a[0]] = 1;
    }else{
        for(int i = 1; i <= m; i++) dp[0][i] = 1;
    }

    for(int i = 1; i < n; i++){
        if(a[i]){
            for(int j = -1; j <= 1; j++){
                int ans = a[i] + j;
                if(ans >= 1 && ans <= m){
                    dp[i][a[i]] += dp[i - 1][ans];
                    dp[i][a[i]] %= mod;
                }
            }
        }else{
            for(int j = 1; j <= m; j++){
                for(int k = -1; k <= 1; k++){
                    int ans = j + k;
                    if(ans >= 1 && ans <= m){
                        dp[i][j] += dp[i - 1][ans];
                        dp[i][j] %= mod;
                    }
                }
            }
        }
    }
    // duyet de tranh truong hop phan tu cuoi la phan tu khong xac dinh
    ll sum = 0;
    for(int i = 1; i <= m; i++){
        sum += dp[n - 1][i];
        sum %= mod;
    }
    cout << sum;
    return 0;
}