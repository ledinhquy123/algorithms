#include <bits/stdc++.h>
using namespace std;
int ok;
void Sinh(string &s){
    int i = s.length() - 1;
    while(i >= 0 && s[i] == '1'){
        s[i] = '0';
        --i;
    }
    if(i == -1) ok = 0;
    else s[i] = '1';
}
int main(){ 
    int n; cin >> n;
    vector<string> v;
    for(int i = 1; i <= n / 2; i++){
        ok = 1;
        string s(i, '0');
        while(ok){
            string t = s;
            reverse(t.begin(), t.end());
            v.push_back(s + t);
            Sinh(s);
        }
    }
    sort(v.begin(), v.end());
    for(auto x : v) cout << x << endl;
    return 0;
}