#include<bits/stdc++.h>
using namespace std;
int n, ok, a[100];
void Sinh(){
    int i = n - 1;
    while(a[i] < a[i + 1] && i >= 1) --i;
    if(i == 0) ok = 0;
    else{
        int j = n;
        while(a[j] > a[i]) --j;
        swap(a[i], a[j]);
        sort(a + i + 1, a + n + 1, greater<int>());
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) a[i] = n - i + 1;
    ok = 1;
    while(ok){
        for(int i = 1; i <= n; i++) cout << a[i];
        cout << endl;
        Sinh();
    }

    return 0;
}