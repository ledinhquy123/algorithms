#include<iostream>
#include<cmath>
using namespace std;
using ll = long long;
const int m = (int)1e9 + 7;
ll solve(ll n, ll k){
    int x = k / (n - 1);
    int r = k % (n - 1);
    if(r == 0) return 1ll * x * n - 1;
    return 1ll * x * n + r;
}
int main(){
    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        cout << solve(n, k) << endl;
    }

    return 0;
}