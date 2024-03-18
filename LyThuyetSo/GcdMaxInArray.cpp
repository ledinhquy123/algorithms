#include<iostream>
#include<limits.h>
#include<cmath>
using namespace std;
int cnt[1000001];
int main(){
    int n; cin >> n;
    int a[n], ans = INT_MIN;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
        ans = max(ans, a[i]);
    }
    for(int i = ans; i >= 1; i--){
        int dem = 0;
        for(int j = i; j <= ans; j+= i){
            dem += cnt[j];
        }
        if(dem > 1){
            cout << i;
            return 0;
        }
    }
    return 0;
}