#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 2e5;
int n, a[maxN];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    ll x = a[n / 2], ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(a[i] - x);
    }
    cout << ans;

    return 0;
}