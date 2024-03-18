#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    a[1] = 1, a[2] = 2;
    for(int i = 1; i <= t; i++){
        int n; cin >> n;
        for(int j = 3; j <= n; j++){
            int s = 1;
            for(int k = 1; k <= j / 2; k++){
                s += a[k];
            }
            a[j] = s;
        }
        cout << i << " " << a[n] << endl;
    }

    return 0;
}