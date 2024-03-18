#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
//Sinh xau nhi phan bang thuat toan quay lui(backtracking)
int x[100], n;
void In(){
    for(int i = 1; i <= n; i++) cout << x[i];
    cout << endl;
}
void Try(int i){
    //Duyet cac kha nang x[i] co the nhan duoc
    for(int j = 0; j <= 1; j++){
        x[i] = j;
        if(i == n){
            In();
        }else{
            Try(i + 1);
        }
    }
}
int main(){
    cin >> n;
    Try(1);
    return 0;
}