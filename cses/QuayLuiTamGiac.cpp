#include<bits/stdc++.h>
using namespace std;
const int maxN = 16;
int n, a[maxN];
vector<string> v;
void solve(int a[], int n){
    if(n > 0){
        string temp = "[";
        for(int i = 0; i < n; i++){
            if(i != n - 1) temp += to_string(a[i]) + " ";
            else temp += to_string(a[i]);
        }
        temp += "]";
        v.push_back(temp);
        for(int i = 0; i < n - 1; i++){
        a[i] = a[i] + a[i + 1];
        }
        solve(a, n - 1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        solve(a, n);
        reverse(v.begin(), v.end());
        for(auto x : v) cout << x << " ";
        cout << endl;
        v.clear();
    }

    return 0;
}