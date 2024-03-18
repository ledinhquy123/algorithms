#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k, a[25], sum;
int res[25], ok;
void solve(int pos, int ans, int dem){
    if(dem - 1 == k){
        ok = 1;
        return;
    }
    if(ok) return;
    for(int j = pos; j <= n; j++){
        if(res[j] == 0){
            res[j] = 1;
            if(ans == sum) solve(j + 1, 0, dem + 1);
            else if(ans <= sum) solve(j + 1, ans + a[j], dem);
            res[j] = 0;
        }   
    }
}
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum % k != 0){
        cout << "0";
        return 0;
    }
    sum /= k;
    solve(1, 0, 0);
    cout << ok;
    return 0;
}