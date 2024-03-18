#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
const int maxN = 1e3 + 1;
int n, k, ok;
int a[20];

void solve(){
    int i = k;
    while(i >= 1 && a[i] == n - k + i) --i;
    if(i == 0) ok = 0;
    else{
        ++a[i];
        for(int j = i + 1; j <= k; j++) a[j] = a[j - 1] + 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= k; i++) a[i] = i;
        ok = 1;
        while(ok){
            for(int i = 1; i <= k; i++) cout << a[i];
            cout << " ";
            solve();
        }
        cout << endl;
    }

    return 0;
}