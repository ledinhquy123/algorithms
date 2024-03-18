#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        int pos = upper_bound(ans.begin(), ans.end(), x) - ans.begin();
        if(pos < ans.size()){
            ans[pos] = x; 
        }else ans.push_back(x);
    }
    cout << ans.size();

    return 0;
}