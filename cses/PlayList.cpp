#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 2e5;
int n, a[maxN];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0, j = 0; i < n; i++){
        while(j < n && mp[a[j]] < 1){
            mp[a[j]]++;
            ++j;
        }
        ans = max(ans, j - i);
        mp[a[i]]--;
    }
    cout << ans;
    
    return 0;
}