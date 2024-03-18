#include<iostream>
#include<limits.h>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
using ll = long long;
const int mod = 1e4 + 7;
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
ll solve(vector<int> v){
    if(v.size() == 0) return 0;
    if(v.size() == 1) return v[0];
    else{
        ll ans = v[0];
        ans %= mod;
        for(int i = 1; i < v.size(); i++){
            ans = lcm(ans , v[i]);
            ans %= mod;
        }
        return ans;
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int &x : a) cin >> x;
        ll sum = 0;
        for(int i = 0; i < (1 << n); i++){
            vector<int> v;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    v.push_back(a[j]);
                }
            }
            sum += solve(v);
        }
        cout << sum << endl;

    }
    return 0;
}