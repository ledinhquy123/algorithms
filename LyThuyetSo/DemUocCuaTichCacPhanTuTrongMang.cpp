#include<iostream>
#include<string>
#include<cmath>
#include<limits.h>
#include<algorithm>
using namespace std;
using ll = long long;
const int mod = 1e9 +7;
ll prime[1000001];
void sieve(){
    for(int i = 2; i <= 1000000; i++){
        prime[i] = i;
    }
    for(int i = 2; i <= sqrt(1000000); i++){
        if(prime[i] == i){
            for(int j = i * i; j <= 1000000; j+= i){
                if(prime[j] == j) prime[j] = i;
            }
        }
    }
}
ll Uoc[1000001];
int main(){
    sieve();
    int n; cin >> n;
    int a[n];
    int res = INT_MIN;
    for(int &x : a){
        cin >> x;
        while(x != 1){
            int temp = prime[x];
            res = max(res, temp);
            int cnt = 0;
            while(x % temp == 0){
                ++cnt;
                x /= temp;
            }
            Uoc[temp] += cnt;
        }
    }
    ll ans = 1;
    for(int i = 2; i <= res; i++){
        ans *= (Uoc[i] + 1);
        ans %= mod;
    }
    cout << ans;
    return 0;
}