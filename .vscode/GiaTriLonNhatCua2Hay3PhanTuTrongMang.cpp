#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    ll x = max(1ll * a[n - 1] * a[n - 2] * a[n - 3], 1ll * a[n - 1] * a[n - 2]);
    ll y = max(1ll * a[0]* a[1] * a[n - 1], 1ll * a[0] * a[1]);
    cout << max(x, y);

    return 0;
}