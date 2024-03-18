#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
//BAI TOAN QUAY LUI N QUAN HAU
//xet cac dong cac cot va xet cac duong cheo
//1 ma tran vuong co 2 * n - 1 duong cheo xuoi va 2 * n - 1 duong cheo nguoc
//Cac de xac dinh vi tri (i, j) nam tren duong cheo xuoi thuoc duong cheo thu may la i - j + n nguoc lai tren duong cheo nguoc la i + j - 1 (hoac i - j + n / 2: DAI KHONG AP DUNG!!)
int a[100], cot[100], c1[100], c2[100], n;
int pos[100][100], cnt = 0;
void In(){
    // for(int i = 1; i <= n; i++){
    //     cout << " Con hau o hang thu " << i << " nam o cot " << a[i];
    //     cout << endl;
    // }
    for(int i = 1; i <= n; i++){
        pos[i][a[i]] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << pos[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void Try(int i){
    for(int j = 1; j <= n; j++){
        //Kiem tra hang va duong cheo xuoi va duong cheo nguoc da co quan hau nao chua
        if(cot[j] == 0 && c1[i - j + n] == 0 && c2[i + j - 1] == 0){
            a[i] = j;
            cot[j] = 1; c1[i - j + n] = 1; c2[i + j - 1] = 1;//Danh dau
            if(i == n){
                // In();
                ++cnt;
            }
            else Try(i + 1);
            //Backtrack
            cot[j] = 0; c1[i - j + n] = 0; c2[i + j - 1] = 0;
        }
    }
}
int main(){
    cin >> n;
    Try(1);
    cout << cnt;

    return 0;
}