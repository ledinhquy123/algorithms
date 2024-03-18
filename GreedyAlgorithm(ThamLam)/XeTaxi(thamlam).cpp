#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    // luu so luong nho co luong nguoi tu 1 -> 4
    int a[5] = {0};
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a[x]++;
    }
    // luu so luong xe taxi
    int ans = a[4] + a[3] + a[2] / 2;
    // can tim cach nhet so luong nhom 1 nguoi vao nhom 3 nguoi va 2 nguoi de so xe taxi al it nhat
    a[1] = (a[1] > a[3]) ? (a[1] - a[3]) : 0;
    a[2] %= 2;
    if(a[2]){
        a[1] = (a[1] > 2) ? (a[1] - 2) : 0;
        ++ans;
    }
    ans += a[1] / 4;
    a[1] %= 4;
    if(a[1]){
        ++ans;
    }
    cout << ans;
    return 0;
}