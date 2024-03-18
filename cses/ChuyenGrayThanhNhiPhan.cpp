#include<bits/stdc++.h>
using namespace std;
const int maxN = 11;
#define ld long double
// chuyen ma gray thanh xau nhi phan
void solve(){
    string s; cin >> s;
    string b = "";
    b += s[0];
    for(int i = 1; i < s.length(); i++){
        if(s[i] == '0'){
            b += b[i - 1];
        }else{
            if(b[i - 1] == '1') b += "0";
            else b += "1";
        }
    }
    cout << b << endl;
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