#include<iostream>
#include<cmath>
using namespace std;
using ll = long long;
//Dung cong thuc legendre
int Legendre(int n, int p){
    int ans = 0;
    for(int i = p; i <= n; i*= p){
        ans += n / i;
    }
    return ans;
}
//Duyet cac so nguyen to tham khao them
int cnt(int n, int p){
    int res = 0;
    for(int i = p; i <= n; i+= p){
        int temp = i;
        while(temp %  p == 0){
            ++res;
            temp /= p;
        }
    }
    return res;
}
bool snt(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return n > 1;
}
ll CountDivisor(int n){
    ll res = 1;
    for(int i = 1; i <= n; i++){
        if(snt(i)){
            res *= (Legendre(n, i) + 1);
        }
    }
    return res;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << CountDivisor(n) << endl;
    }
    return 0;
}
//n = p1 ^ e1 * p2 ^ e2 * ... * pn ^ en :  phan tich 1 so thanh tich cac so nguyen to
//d(n) = (e1 + 1) * (e2 + 1) * .. * (en + 1): dem uoc cua n dua vao phan tich thua so nguyen to
// dem uoc cua n giai thua bang cach phan tich so lan xuat hien cua cac so la so nguyen to tu 1 den n