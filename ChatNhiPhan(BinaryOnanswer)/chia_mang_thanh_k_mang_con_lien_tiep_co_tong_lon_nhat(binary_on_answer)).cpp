#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int n, k, a[200001];
bool check(ll x){
    ll sum = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        if(sum > x){
            sum = a[i];
            ++cnt;
        }
    }
    ++cnt;
    return cnt <= k;
}
int main(){
    cin >> n >> k;
    ll sum = 0;
    int max_val = INT_MIN;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        max_val = max(max_val, a[i]);
    }
    ll left = max_val, right = sum;
    ll ans = 0;
    while(left <= right){
        ll m = (left + right) / 2;
        if(check(m)){
            ans = m;
            right = m - 1;
        }else left = m + 1;
    }
    cout << ans;
    return 0;
}