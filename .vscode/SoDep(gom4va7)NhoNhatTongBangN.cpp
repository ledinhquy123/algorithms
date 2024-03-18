#include<bits/stdc++.h>
using namespace std;
const int mod = (int)(1e9 + 7);
using ll = long long;
int main(){
    int n; cin >> n;
    for(int i = n / 7; i >= 0; i--){
        if((n - i * 7) % 4 == 0){
            cout << string((n - i * 7) / 4, '4') << string(i, '7');
            return 0;
        }
    }
    cout << -1;
    return 0;
}