#include<bits/stdc++.h>
using namespace std;
int a[100], n, k;
void In(){
    for(int i = 1; i <= k; i++){
        cout << a[i];
    }
    cout << endl;
}
void Try(int i){
    //Cau hinh lon nhat co the dat duoc tai i la: n - k +i;
    //Cau hinh nho nhat co the dat duoc tai i se phu thuoc vao phan tu truoc no vi trong sinh tap con thi cau hinh thuong tang dan nen la: a[i - 1] + 1
    for(int j = a[i - 1] + 1; j <= n - k + i; j++){
        a[i] = j; //Thong thuong tai day se xet truong hop
        if(i == k) In();
        else Try(i + 1);
    } 
}
int main(){
    cin >> n >> k;
    Try(1);
    return 0;
}