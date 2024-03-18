#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e6;
const int mod = 1e9 + 7;
#define ll long long
int n, dp[maxN];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n;
    for(int i = 1; i <= n; i++){
        dp[i] = 1e9;
        int i1 = i;
        while(i1){
            dp[i] = min(dp[i], dp[i - i1 % 10] + 1);
            i1 /= 10;
        }
    }
    cout << dp[n];

    return 0;
}