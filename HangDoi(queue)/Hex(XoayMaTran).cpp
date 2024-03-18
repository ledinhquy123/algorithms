#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> XoayTrai(vector<int> v){
    vector<int> res(6);
    res[0] = v[3]; res[1] = v[0];
    res[2] = v[2]; res[3] = v[4]; 
    res[4] = v[1]; res[5] = v[5];
    return res;
}
vector<int> XoayPhai(vector<int> v){
    vector<int> res(6);
    res[0] = v[0]; res[1] = v[4];
    res[2] = v[1]; res[3] = v[3];
    res[4] = v[5]; res[5] = v[2];
    return res;
}
bool check(vector<int> s, vector<int> t){
    for(int i = 0; i < 6; i++){
        if(s[i] != t[i]) return false;
    }
    return true;
}
int bfs(vector<int> s, vector<int> t){
    queue<pair<vector<int>, int>> q;
    q.push({s, 0});
    set<vector<int>> se;
    se.insert(s);
    while(!q.empty()){
        pair<vector<int>, int> temp = q.front(); q.pop();
        if(check(temp.first, t)) return temp.second;
        vector<int> trai = XoayTrai(temp.first);
        if(!se.count(trai)){
            q.push({trai, temp.second + 1});
            se.insert(trai);
        }
        vector<int> phai = XoayPhai(temp.first);
        if(!se.count(phai)){
            q.push({phai, temp.second + 1});
            se.insert(phai);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    vector<int> s(6), t(6);
    for(int &x : s) cin >> x;
    for(int &x : t) cin >> x;
    cout << bfs(s, t);

    return 0;
}