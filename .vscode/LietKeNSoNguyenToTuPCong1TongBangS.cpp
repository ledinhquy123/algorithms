#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int n, p, s, x[100], used[100];
vector<int> prime;
vector<vector<int>> result;
bool snt(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return n > 1;
}
void init(){
    prime.clear(); result.clear();
    memset(used, 0, sizeof(used));
    cin >> n >> p >> s;
    for(int i = p + 1; i <= s; i++){
        if(snt(i)){
            prime.push_back(i);
        }
    }
}
void solve(int sum, int pos, int cnt){
    if(sum == s && n == cnt){
        vector<int> temp(x, x + cnt);
        result.push_back(temp);
        return;
    }
    for(int i = pos; i < prime.size(); i++){
        if(!used[i] && sum + prime[i] <= s){
            x[cnt] = prime[i];
            used[i] = 1;
            solve(sum + prime[i], i, cnt + 1);
            used[i] = 0;
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        init();
        solve(0, 0, 0);
        cout << result.size() << endl;
        for(auto x : result){
            for(auto it : x) cout << it << " ";
            cout << endl;
        }
    }

    return 0;
}