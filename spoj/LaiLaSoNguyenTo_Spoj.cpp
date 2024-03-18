#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool stn(ll n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return n > 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int cnt = 0;
        if(stn(n)) cnt++;
        for(int i = 2; i <= n / 2; i++){
            if(stn(i)){
                ll sum = 0;
                for(int j = i; j <= n; j++){
                    if(stn(j)){
                        sum += j;
                        if(sum == n) cnt++;
                        if(sum > n) break;
                    }
                }
            }
            
        }
        cout << cnt << endl;
    }

    return 0;
}