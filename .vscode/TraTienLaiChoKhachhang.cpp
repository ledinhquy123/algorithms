#include<bits/stdc++.h>
using namespace std;
bool solve(int a[], int n){
    int a25 = 0, a50 = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 25) ++a25;
        else if(a[i] == 50){
            if(a25 == 0) return false;
            --a25;
            ++a50;
        }else{
            if(a25 == 0 || a25 * 25 + a50 * 50 < 75) return false;
            if(a50){
                --a50; --a25;
            }else{
                a25 -= 3;
            }
        }
    }
    return true;
}
int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    if(solve(a, n)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}