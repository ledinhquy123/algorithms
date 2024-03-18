#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll x, y; cin >> x >> y;
    while(1){
        if(y % x == 0){
            cout << 1 << "/" << y / x;
            return 0;
        }
        ll res = y / x + 1;
        cout << 1 << "/" << res << " + ";
        x = x * res - y;
        y *= res;
    }

    return 0;
}