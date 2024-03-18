#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n; cin >> n;
    map<int, int> mp;
    mp[0] = 1;
    ll sum = 0, ans = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        sum += x;
        ans += mp[(sum % n + n) % n];
        mp[(sum % n + n) % n]++;
    }
    cout << ans;
    return 0;
}