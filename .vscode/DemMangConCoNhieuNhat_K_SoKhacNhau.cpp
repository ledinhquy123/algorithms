#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n, k; cin >> n >> k;
    map<int, int> mp;
    ll ans = 0, left = 0, cnt = 0;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
        if(mp[a[i]] == 1) ++cnt;
        while(cnt > k){
            --mp[a[left]];
            if(mp[a[left]] == 0) --cnt;
            ++left;
        }
        ans += (i - left + 1);
    }
    cout << ans;

    return 0;
}