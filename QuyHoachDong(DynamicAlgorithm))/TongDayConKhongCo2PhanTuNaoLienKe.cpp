#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int s[n] = {0};
    s[0] = a[0];
    s[1] = max(a[1], a[0]);
    for(int i = 2; i < n; i++){
        s[i] = max(s[i - 2] + a[i], s[i - 1]);
    }
    cout << s[n - 1];

    return 0;
}