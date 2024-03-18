#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 1;
int n, a[maxn], ok;

void solve(){
    int i = n - 1;
    while(i >= 1 && a[i] < a[i + 1]) --i;
    if(i == 0) ok = 0;
    else{
        int j = n;
        while(a[j] > a[i]) --j;
        swap(a[i], a[j]);
        reverse(a + i + 1, a + n + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) a[i] = n - i + 1;
        ok = 1;
        while(ok){
            for(int i = 1; i <= n; i++) cout << a[i];
            cout << " ";
            solve();
        }
        cout << endl;
    }

    return 0;
}