#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int dp1[n] = {0};
    for(int i = 0; i < n; i++){
        dp1[i] = a[i];
        for(int j = 0; j < i; j++){
            if(a[i] > a[j]) dp1[i] = max(dp1[i], dp1[j] + a[i]);
        }
    }

    int dp2[n] = {0};
    for(int i = n - 1; i >= 0; i--){
        dp2[i] = a[i];
        for(int j = n - 1; j > i; j--){
            if(a[i] > a[j]) dp2[i] = max(dp2[i], dp2[j] + a[i]);
        }
    }
    int ans = -1e9;
    for(int i = 0; i < n; i++){
        ans = max(ans, dp1[i] + dp2[i] - a[i]);
    }
    cout << ans;
    return 0;
}