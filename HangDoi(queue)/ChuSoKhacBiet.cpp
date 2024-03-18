#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// chu so khac biet
bool used[100001];
vector<int> v;
void tach(int x){
    while(x > 0){
        int r = x % 10;
        used[r] = true;
        x /= 10;
    }
}
void solve(){
    queue<int> q;
    q.push(1); q.push(2); q.push(3); q.push(4); q.push(5);
    while(!q.empty()){
        int temp = q.front(); q.pop();
        if(temp > 1e5) break;
        v.push_back(temp);
        tach(temp);
        for(int i = 0; i <= 5; i++){
            if(!used[i]){
                q.push(temp * 10 + i);
            }
        }
        memset(used, false, sizeof(used));
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    solve();
    while(t--){
        int l, r; cin >> l >> r;
        int cnt = 0;
        for(auto x : v){
            if(x >= l && x <= r) ++cnt;
        }
        cout << cnt << endl;
    }

    return 0;
}