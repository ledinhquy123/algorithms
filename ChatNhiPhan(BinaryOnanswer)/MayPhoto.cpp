#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, x, y;
bool check(ll time){
    ll a = time / x;
    ll b = time / y;
    // Tru di 1 de loai ban goc ra 
    return a + b >= 1ll * (n - 1);
}
int main(){
    cin >> n >> x >> y;
    ll left = min(x, y), right = 1ll * max(x, y) * n, ans = 0;
    // bien res luu tgian phô tô ra bản đầu tiên để lần tiếp theo 2 máy có thế hoạt động cùng lúc
    ll res = left;  
    while(left <= right){
        ll m = (left + right) / 2;
        if(check(m)){
            ans = m;
            right = m - 1;
        }else left = m + 1;
    }
    cout << ans + res;
    return 0;
}