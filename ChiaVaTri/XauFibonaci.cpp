#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll fb[93];
void init(){
    fb[1] = 1;
    fb[2] = 1;
    for(int i = 3; i <= 92; i++) fb[i] = fb[i - 1] + fb[i - 2];
}
char solve(int n, int k){
    if(n == 1) return 'A';
    if(n == 2) return 'B';
    if(k <= fb[n - 2]) return solve(n - 2, k);
    return solve(n - 1, k - fb[n - 2]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    init();
    cout << solve(n, k);

    return 0;
}