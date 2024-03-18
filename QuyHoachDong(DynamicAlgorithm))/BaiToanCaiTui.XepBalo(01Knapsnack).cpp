#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int n, s; cin >> n >> s;
    int w[n + 1], v[n + 1];
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) cin >> v[i];
    int dp[n + 1][s + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= s; j++){
            //Khong lua chon do vat vao trong tui
            dp[i][j] = dp[i - 1][j];
            if(j >= w[i]){
                //Co the lua chon do vat vao trong tui
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[n][s] << endl;
    return 0;
}