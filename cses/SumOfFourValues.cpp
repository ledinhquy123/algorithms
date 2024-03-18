#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e3;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x; cin >> n >> x;
    vector<pair<int, int>> a;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back({x, i}); 
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; ++j){
            int sum = x - a[i].first - a[j].first;
            int l = j + 1, r = n - 1;
            while(l < r){
                ll ans = a[l].first + a[r].first;
                if(ans < sum) ++l;
                else if(ans > sum) --r;
                else{
                    cout << a[i].second + 1 << " " << a[j].second + 1 << " " << a[l].second + 1 << " " << a[r].second + 1;
                    return 0;
                }
            }
        }   
    }
    cout << "IMPOSSIBLE";

    return 0;
}