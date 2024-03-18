#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pil pair<int, ll>
int n, k;
int a[50], post[50];

void solve(){
    int i = k;
    while(i >= 1 && a[i] == n - k + i) --i;
    if(i == 0){
        cout << k << endl;
    }
    else{
        ++a[i];
        for(int j = i + 1; j <= k; j++){
            a[j] = a[j - 1] + 1;
        }

        int cnt = 0;
        for(int i = 1; i <= k; i++){
            if(!post[a[i]]) ++cnt;
        }
        cout << cnt << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while(t--){
        memset(post, 0, sizeof(post));
        cin >> n >> k;
        for(int i = 1; i <= k; i++){
            cin >> a[i];
            post[a[i]] = 1;
        }
        solve();
    }

    return 0;
}