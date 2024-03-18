#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits.h>
using namespace std;
using ll = long long;
const int mod = (int)1e9 + 7;
//Tim nghiem pt:11x + 111y = n
bool check(ll n){
    for(ll i = 0; i <= n / 11; i++){
        if((n - 11 * i) % 111 == 0) return true;
    }
    return false;
}
int main(){
    ll n; cin >> n;
    if(check(n)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}