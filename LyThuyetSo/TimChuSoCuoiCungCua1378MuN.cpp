#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
using ll = long long;
//Cach 1
ll solve(int a, ll b){
    ll res = 1;
    while(b){
        if(b & 1){
            res *= a;
            res %= 10;
        }
        a *= a;
        a %= 10;
        b >>= 2;
    }
    return res;
}
//Cach 2
void solve2(ll n){
    if(n % 4 == 1) cout << "8\n";
    if(n % 4 == 2) cout << "4\n";
    if(n % 4 == 3) cout << "2\n";
    if(n % 4 == 0) cout << "6\n";
}
int main(){
    ll n; cin >> n;
    // cout << solve(1378, n);
    solve2(n);
    return 0;
}
//Cach don gian ngan gon v ma minh khong biet minh ngu qua di :v
//Cach 2 dua vao vong tuan hoan tan cung cua 2 
//2^1 = 2, 2^2 = 4, 2^3 = 8, 2^4 = 6.. tuong tu no se lap lai
//8^1 = 8, 8^2 = 4, 8^3 = 2, 8^4 = 6... tuong tu no se lap lai 
//Chu y so chia het cho 4 co tan cung la 6