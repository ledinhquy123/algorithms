#include<bits/stdc++.h> 
using namespace std;   
using ld = long double;
using ll = long long;
int main(){
    int n; cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        v.push_back({x, 1});
        v.push_back({y, -1});
    }
    sort(v.begin(), v.end());
    ll ans = 0, res = INT_MIN;
    for(auto x : v){
        ans += x.second;
        res = max(res, ans);
    }
    cout << res;
    return 0;
}