#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string a, n; cin >> a >> n;
    int temp = a[a.length() - 1] -'0';
    if(temp == 0 || temp == 1 || temp == 5 || temp == 6){
        cout << temp;
        return 0;
    }
    int r;
    if(n.length() == 1) r = n[n.length() - 1] - '0';
    else r = (n[n.length() - 2] - '0') * 10 + (n[n.length() - 1] - '0');
    int r2[4] = {6, 2, 4, 8};
    int r3[4] = {1, 3, 9, 7};
    int r4[4] = {6, 4, 6, 4};
    int r7[4] = {1, 7, 9, 3};
    int r8[4] = {6, 8, 4, 2};
    int r9[4] = {1, 9, 1, 9};
    r %= 4;
    if(temp == 2) cout << r2[r];
    if(temp == 3) cout << r2[r];
    if(temp == 4) cout << r4[r];
    if(temp == 7) cout << r7[r];
    if(temp == 8) cout << r8[r];
    if(temp == 9) cout << r7[r];
    return 0;
}