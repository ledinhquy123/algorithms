#include<iostream>
#include<string>
#include<limits.h>
#include<algorithm>
#include<cmath>
using namespace std;
using ll = long long;
const int mod = 1e9 +7;
ll PowMod(ll a, ll b){
	ll res = 1;
	a %= mod;
	while(b){
		if(b & 1){
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return res;
}
int main(){
	ll n, k; cin >> n >> k;
	ll ans = 0, res = 0;
	while(k){
		if(k & 1){
			res = PowMod(n, ans);
			res %= mod;
		}
		ans++;
		k >>= 1;
	}
	cout << res;
	return 0;
}