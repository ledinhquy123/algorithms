#include<iostream>
#include<fstream>
#include<algorithm>
#include<map>
using namespace std;
using ll = long long;
int x, y, d;
void Extended(int a, int b){
    if(b == 0){
        y = 0; x = 1; d = a;
    }else{
        Extended(b, a % b);
        int temp = x;
        x = y;
        y = temp - (a / b) * y;
    }
}
ll Inverser1(int a, int m){
    Extended(a, m);
    if(d != 1){
        cout << "Khong ton tai";
        exit(0);
    }else{
        return (x % m + m) % m;
    }
}
ll PowMod(ll a, ll b, ll m){
    ll res = 1;
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
ll Inverser2(ll a, ll m){
    return PowMod(a, m - 2, m);
}
int main(){
    ll a, m; cin >> a >> m;
    cout << Inverser1(a, m) << endl;
    cout << Inverser2(a, m) << endl;
    return 0;
}