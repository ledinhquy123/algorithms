#include<iostream>
#include<cmath>
using namespace std;
using ll = long long;
int gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}
int lcm(ll a, ll b){
    return (a * b) / gcd(a, b);
}
ll solve(int x, int y, int z, int n){
    ll tmp = lcm(lcm(x, y), z);
    ll ans = (ll)pow(10, n - 1);
    ll res = (ans + tmp - 1) / tmp * tmp;
    if(tmp < (ll)pow(10, n)) return res;
    return -1;
}
int main(){
    int x, y, z, n; cin >> x >> y >> z >> n;
    cout << solve(x, y, z, n);
    return 0;
}