#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int a[1001][10001]; // luu ma tran ke
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            //Neu danh sach co huong thi duyet i < j con co huong thi in ra tat ca
            if(i > j && a[i][j]) cout << i << " " << j << endl;
        }
    }
    cout << endl;
    for(int i = 1; i <= n; i++){
        cout << i << " : ";
        for(int j = 1; j <= n; j++){
            if(a[i][j]){
                cout << j << " ";
            }
        }
        cout << endl;
    }

    return 0;
}