#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//Dung sinh hoac quay lui de sinh tat ca cac tap con se khong hop li trong bai nay
int main(){
    int n, s; cin >> n >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<bool> dp(s + 1, false);
    dp[0] = true;
    for(int i = 0; i < n; i++){
        for(int j = s; j >= a[i]; j--){
            if(dp[j - a[i]] == true) dp[j] = true;
        }
    }
    if(dp[s]) cout << "1\n";
    else cout << "0\n";
    return 0;
}
//Bai toan nay y tuong la lay 1 vector dp de luu kha nang co the tao thanh tong s hay khong khoi tao tu 0 den s moi lan duyet se di tu s ve a[i] va xet dp[j - a[i]] 
//Neu xet tu 0 den s thi 1 phan tu cua mang se duoc dung nhieu lan k phu hop yeu cau bai toan