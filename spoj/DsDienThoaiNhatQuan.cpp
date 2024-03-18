#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = (int)(1e4 + 1);
string a[maxN];
int n;
bool check(){
    sort(a, a + n);
    bool ok = false;
    for(int i = 0; i < n - 1; i++){
        bool temp = false;
        for(int j = 0; j < a[i].length(); j++){
            if(a[i][j] != a[i + 1][j]){
                temp = true;
                break;
            }
        }
        if(!temp){
            ok = true;
            break;
        }
    }
    return !ok;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(check()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}