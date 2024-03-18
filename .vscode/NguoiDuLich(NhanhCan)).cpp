#include<bits/stdc++.h>
//nhanh can bia toan du lich
using namespace std;
const int mod = (int)(1e9 + 7);
using ll = long long;
//dung 1 bien ans luu ket qua, sum cap nhap chi phi
//Tim chi phi min giua 2 thanh pho bat ki: cmin
//n thanh pho, da di duoc k thanh pho thi nhung thanh pho con lai chua di tham se la n - k
//sum + (n - k) * cmin > ans (ket qua da luu trc do) -> cat canh
int n, c[20][20], cmin = 1e9, sum, ans = 1e9, used[100], x[100];
void inp(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
            if(c[i][j]) cmin = min(cmin, c[i][j]);
        }
    }
}
void Try(int i){
    for(int j = 2; j <= n; j++){
        if(used[j] == 0){
            used[j] = 1;
            x[i] = j;
            sum += c[x[i - 1]][x[i]];
            if(i == n) ans = min(ans, sum + c[x[i]][1]);
            else if(sum + (n - i) * cmin < ans) Try(i + 1);
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