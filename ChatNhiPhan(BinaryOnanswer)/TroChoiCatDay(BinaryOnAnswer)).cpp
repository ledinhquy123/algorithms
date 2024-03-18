#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int n, k, a[10001];
bool check(ld x){
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += (ll)(a[i] / x);
    }
    return ans >= k;
}
int main(){
    cin >> n >> k;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    ld res = INT_MIN, left = 0, right = sum;
    for(int i = 0; i < 250; i++){
        ld m = (ld)(left + right) / 2;
        if(check(m)){
            left = m;
            res = max(res, m);
        }else right = m;
    }
    cout << fixed << setprecision(6) << res;
    return 0;
}