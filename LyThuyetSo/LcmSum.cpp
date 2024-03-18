#include<iostream>
#include<cmath>
using namespace std;
using ll = long long;
// Dung de sang phi ham euler, res luu cac LCM SUM tu 1 den 10^6
ll p[1000001], res[1000001];
void EulerSieve(){
    for(int i = 1; i <= 1000000; i++){
        p[i] = i;
    }
    for(int i = 2; i <= 1000000; i++){
        if(p[i] == i) p[i] = i - 1;
        for(int j = 2 * i; j <= 1000000; j+= i){
            p[j] -= p[j] / i;
        }
    }
}
void sieve(){
    for(int i = 1; i <= 1000000; i++){
        for(int j = i; j <= 1000000; j+= i){
            res[j] += 1ll * i * p[i];
        }
    }
}
int main(){
    EulerSieve();
    sieve();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << (1ll * res[n] + 1) * n / 2 << endl;
    }
    return 0;
}
//lcm sum
//Vd: 6 thi lcm sum(6) = (1 * phi(1) + 2 * phi(2)+ 3 * phi(3) + 6 * phi(6) + 1) * n / 2