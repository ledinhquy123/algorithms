#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 5e3;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int, int>> a;
    int n, x; cin >> n >> x;
    for(int i = 0; i < n; ++i){
        int y; cin >> y;
        a.push_back({y, i});
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        int sum = x - a[i].first;
        int left = i + 1, right = n - 1;
        while(left < right){
            ll ans = a[left].first + a[right].first;
            if(ans > sum) --right;
            else if(ans < sum) ++left;
            else{
                cout << a[i].second + 1 << " " << a[left].second + 1 << " " << a[right].second + 1;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}