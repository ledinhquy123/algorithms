#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int ,int> a, pair<int, int> b){
    if(abs(a.first) != abs(b.first)) return abs(a.first) < abs(b.first);
    return a.second < b.second;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v[i].first = x;
            v[i].second = i;
        }
        sort(v.begin(), v.end(), comp);
        int res = INT_MAX, ans = INT_MAX;
        int index = -1;
        for(int i = 1; i < n; i++){
            int sum = abs(v[i - 1].first + v[i].first);
            if(sum < res){
                res = sum;
                ans = v[i - 1].first + v[i].first;
                index = min(v[i - 1].second, v[i].second);
            }else if(sum == res){
                if(index > min(v[i - 1].second, v[i].second)){
                    ans = v[i - 1].first + v[i].first;
                    index = min(v[i - 1].second, v[i].second);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}