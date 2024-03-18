#include<bits/stdc++.h>
using namespace std;
const int maxN = 2e5;
#define ll long long
int a[maxN], n, x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    map<ll, int> mp;
    mp[0] = 1;
    ll s = 0, ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
        ans += mp[s - x];
        mp[s]++;
    }
    cout << ans;
    return 0;
}