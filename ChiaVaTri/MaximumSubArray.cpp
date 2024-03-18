#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll CrossSum(int a[], int l, int r){
    ll sum = 0, LeftSum = -1e9, RightSum = -1e9;
    int m = (l + r) / 2;
    for(int i = m; i >= l; i--){
        sum += a[i];
        LeftSum = max(LeftSum, sum);
    }
    sum = 0;
    for(int i = m + 1; i <= r; i++){
        sum += a[i];
        RightSum = max(RightSum, sum);
    }
    return max({LeftSum, RightSum, LeftSum + RightSum});
}
ll solve(int a[], int l, int r){
    if(l == r) return a[l];
    int m = (l + r) / 2;
    return max({solve(a, l, m), solve(a, m + 1, r), CrossSum(a, l, r)});
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << solve(a, 0, n - 1);
    return 0;
}