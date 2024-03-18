#include<bits/stdc++.h>
using namespace std;
int pos[100], a[100], n;
void In(){
    for(int i = 1; i <= n; i++) cout << a[i];
    cout << endl;
}
void Try(int i){
    //Duyet cac kha nang a[i] co the nhan duoc
    for(int j = 1; j <= n; j++){
        //Check xem co the gan a[i] = j hay khong??
        if(pos[j] == 0){
            a[i] = j;
            pos[j] = 1;//Danh dau j da xuat hien
            if(i == n) In();
            else Try(i + 1);
            pos[j] = 0;
        }
    }
}
int main(){
    cin >> n;
    Try(1);

    return 0;
}