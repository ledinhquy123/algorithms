#include<bits/stdc++.h>
using namespace std;
int main(){ 
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        int sum = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            sum += a[i];
        }
        if(sum & 1){
            cout << "NO\n";
            return 0;
        }
        vector<bool> dp(sum / 2 + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = sum / 2; j >= 0; j--){
                if(j - a[i]) dp[j] = true;
            }
        }
        if(dp[sum / 2]) cout << "YES\n";
    }
    return 0;
}