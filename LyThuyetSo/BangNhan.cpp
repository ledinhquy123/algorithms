#include<iostream>
#include<cmath>
using namespace std;
using ll = long long;
ll solve(ll n, ll x){
    ll ans = 0;
    for(ll i = 1; i <= sqrt(x); i++){
        if(x % i == 0){
            if(i != x / i){
                if(i <= n && x / i <= n) ans += 2;
            }
            else{
                if(i <= n) ++ans;
            }
        }
    }
    return ans;
}
int main(){
    ll n, x; cin >> n >> x;
    cout << solve(n, x);
    return 0;
}