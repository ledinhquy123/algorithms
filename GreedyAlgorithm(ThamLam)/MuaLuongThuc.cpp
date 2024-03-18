#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int s, n, m; cin >> n >> s >> m;
    if(n * (s - s / 7) < s * m){
        cout << -1;
        return 0;
    }
    for(int i = 0; i <= s - s / 7; i++){
        if(i * n >= s * m){
            cout << i;
            return 0;
        }
    }
    return 0;
}