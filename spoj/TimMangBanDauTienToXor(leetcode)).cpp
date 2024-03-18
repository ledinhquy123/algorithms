#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxN = 1e5 + 1;

int pref[maxN], n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x;
    while(cin >> x){
        pref[n++] = x;
    }
    
    int ans[n + 1];
    ans[0] = pref[0];

    int temp = ans[0];
    for(int i = 1; i < n; i++){
        ans[i] = temp ^ pref[i];
        temp ^= ans[i];
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}