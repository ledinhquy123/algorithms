#include<bits/stdc++.h>
using namespace std;
// ti va teo choi string game lay ra 1 ki tu bat ki va sap dat lai sao cho chuoi doi xung se win
int main(){
    string s; cin >> s;
    map<int, int> mp;
    for(char x : s){
        mp[x]++;
    }
    vector<int> v;
    for(auto it : mp){
        if(it.second % 2 != 0) v.push_back(it.second);
    }
    if(v.size() <= 1) cout << "1";
    else{
        if((v.size() - 1) % 2 == 0) cout << "1";
        else cout << "2";
    }
    return 0;
}