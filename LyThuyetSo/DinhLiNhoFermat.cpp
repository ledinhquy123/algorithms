#include<iostream>
#include<limits.h>
#include<cmath>
#include<string>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
//Dinh li nho fermat
ll PowMod(ll a, ll b, ll m){
    ll res = 1;
    a %= m;
    while(b){
        if(b & 1){
            res *= a;
            res %= m;
        }
        a *= a;
        a %= m;
        b >>= 1;
    }
    return res;
}
int main(){
    int n; cin >> n;
    while(n--){
        ll a, b, c; cin >> a >> b >> c;
        ll res = PowMod(b, c, mod - 1);
        ll ans = PowMod(a, res, mod);
        cout << ans << endl;
    }
   return 0;
}