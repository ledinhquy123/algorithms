#include<iostream>
using namespace std;
using ll = long long;
ll solve(int n, ll k){
    int q = n / k;
    int r = n % k;
    ll sum1 = 0, sum2 = 0;
    sum1 += 1ll * (k - 1) * k / 2;
    sum2 += 1ll * r * (r + 1) / 2;
    return 1ll * q * sum1 + sum2;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; ll k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}