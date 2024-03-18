#include<bits/stdc++.h>
using namespace std;
int main(){
    string s; cin >> s;
    map<char, int> mp;
    for(char x : s){
        mp[x]++;
    }
    int Max = -1e9;
    for(auto x : mp){
        Max = max(Max, x.second);
    }
    if(s.length() % 2 == 0 && Max <= s.length() - Max) cout << "YES";
    else if(s.length() % 2 == 1 && Max <= s.length() / 2 + 1) cout << "YES";
    else cout << "NO";
    return 0;
}