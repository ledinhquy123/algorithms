#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
using ll = long long;
const int maxN = 1e3;
// chuyen nhi phan thanh ma gray
void solve(){
    string s; cin >> s;
    string gray = "";
    gray += s[0];
    for(int i = 1; i < s.length(); i++){
        if(s[i - 1] == '1'){
            if(s[i] == '1') gray += "0";
            else gray += "1";
        }else gray += s[i];
    }
    cout << gray << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}