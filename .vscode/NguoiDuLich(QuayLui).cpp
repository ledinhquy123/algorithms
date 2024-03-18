#include<bits/stdc++.h>
using namespace std;
// nguoi du lich
// CACH NAY THI KHONG AC DUOC CHO N LEN TOI 15
int n, c[101][101], used[100], x[100], ans = 1e9, sum;
void inp(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cin >> c[i][j];
    }
}
// x[i - 1] => x[i]
// chi phi: c[x[i - 1]][x[i]]
void Try(int i){
    for(int j = 2; j <= n; j++){
        if(used[j] == 0){
            x[i] = j;
            used[j] = 1;
            // cap nhat chi phi duong di
            sum += c[x[i - 1]][x[i]];
            if(i == n){
                // de quay lai thanh pho dau tien
                ans = min(ans, sum + c[x[i]][1]);
            }else Try(i + 1);
            used[j] = 0;
            sum -= c[x[i - 1]][x[i]];
        }
    }
}
int main(){
    inp();
    x[1] = 1;
    Try(2);
    cout << ans;
    return 0;
}