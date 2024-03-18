#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> a;
void init(){
    vector<string> v;
    v.push_back("0"); v.push_back("1");
    a.push_back(v);
    for(int i = 2; i <= 16; ++i){
        vector<string> b(a[i - 2]); // 01
        reverse(b.begin(), b.end()); // 10
        vector<string> x;
        for(int j = 0; j < a[i - 2].size(); ++j){
            x.push_back("0" + a[i - 2][j]); // 00 01
        }
        for(int j = 0; j < b.size(); ++j){
            x.push_back("1" + b[j]); // 11 10
        }
        a.push_back(x);
        // do dai 3 tuong tu 2
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    int n; cin >> n;
    for(string x : a[n - 1]) cout << x << endl;

    return 0;
}