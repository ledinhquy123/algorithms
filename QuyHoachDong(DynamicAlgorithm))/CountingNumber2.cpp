#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// đếm trong đoạn từ a đến b có bao nhiêu số mà có tổng các chữ số bằng 1 số nguyên tố
int prime[82];
void init(){
    for(int i = 1; i <= 81; i++){
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for(int i = 2; i <= sqrt(81); i++){
        if(prime[i]){
            for(int j = i * i; j <= 81; j+= i){
                prime[j] = 0;
            }
        }
    }
}
ll SumDigit(int n, int x){
    ll dp[10][100][2];
    //dp[i][sum][0] : lưu số lương các số tại vị trí i có tổng bằng sum và có trạng thái là 0
    //dp[i][sum][1] : lưu số lương các số tại vị trí i có tổng bé hơn sum và có trạng thái là 1
    memset(dp, 0, sizeof(dp));
    string s = to_string(n);
    for(int i = 0; i < s[0] - '0'; i++){
        dp[0][i][1] = 1;
    }
    dp[0][s[0] - '0'][0] = 1;
    for(int i = 1; i < s.length(); i++){
        for(int j = 0; j <= 9; j++){
            for(int sum = j; sum <= x; sum++){
                dp[i][sum][1] += dp[i - 1][sum - j][1];
                if(j < s[i] - '0') dp[i][sum][1] += dp[i - 1][sum - j][0];
                else if(j == s[i] - '0') dp[i][sum][0] += dp[i - 1][sum - j][0];
            }
        }
    }
    return dp[s.length() - 1][x][0] + dp[s.length() - 1][x][1]; 
}
int main(){
    init();
    int a, b; cin >> a >> b;
    ll ans = 0, res = 0;
    for(int i = 0; i <= 81; i++){
        if(prime[i]){
            // tương tự prefix sum
            ans += SumDigit(b, i);
            res += SumDigit(a - 1, i);
        }
    }
    cout << ans - res;
    return 0;
}