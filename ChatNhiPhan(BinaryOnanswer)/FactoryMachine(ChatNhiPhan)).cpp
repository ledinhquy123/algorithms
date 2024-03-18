#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int n, t, a[200001];
bool check(ll time){
    //Kiem tra trong 1 khoang thoi gian cac may co the tao ra 't' san pham hay khong
    ll res = 0;
    for(int i = 0; i < n; i++){
        res += time / a[i];
    }
    return res >= t;
}
int main(){
    cin >> n >> t;
    for(int i = 0; i < n; i++) cin >> a[i];
    ll left = 0, right = 1ll * t * (*min_element(a, a + n)); //Xac dinh tgian toi thieu va toi da co the
    ll ans = -1;
    //Chat nhi phan de quan li (tuong tu merge)
    while(left <= right){
        ll mid = (left + right) / 2;
        if(check(mid)){
            ans = mid;
            right = mid - 1;
        }else left = mid + 1;
    }
    cout << ans << endl;
    return 0;
}