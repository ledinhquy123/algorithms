#include<bits/stdc++.h>
using namespace std;
#define ll  long long
const int maxN = 2e5;
const int mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    ll time = v[0].first, price = v[0].second - v[0].first;
    for(int i = 1; i < n; i++){
        time += v[i].first;
        price += (v[i].second - time);
    }
    cout << price;

    return 0;
}