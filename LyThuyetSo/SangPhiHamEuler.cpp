#include<iostream>
#include<cmath>
using namespace std;
using ll = long long;
int el[1000001],n;
void sieve(){
    for(int i = 1; i <= 100000; i++){
        el[i] = i;
    }
    for(int i = 2; i <= 1000000; i++){
        if(el[i] == i) el[i] = i - 1;
        for(int j = 2 * i; j <= 1000000; j+= i){
            el[j] -= el[j] / i;
        }
    }
}
int main(){
    sieve();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 1; i <= n; i++) cout << el[i] << " ";
        cout << endl;
    }

    return 0;
}