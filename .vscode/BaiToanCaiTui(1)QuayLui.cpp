#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e3 + 1;
int n, s;
vector<pair<int, int>> v;
int backTrack(int pos, int trongluong, int val){
    if(trongluong > s) return 0;
    if(pos == n && trongluong <= s){
        return val;
    } 
    int x = backTrack(pos + 1, trongluong + v[pos].first, val + v[pos].second);
    int y = backTrack(pos + 1, trongluong, val);
    return max(x, y);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), [](pair<int, int> x, pair<int, int> y)->bool{
        return (float)x.second / x.first > (float)y.second / y.first;
    });
    cout << backTrack(0, 0, 0);

    return 0;
}