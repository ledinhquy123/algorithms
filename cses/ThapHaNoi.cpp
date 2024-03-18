#include<bits/stdc++.h>
using namespace std;
const int maxN = 11;
void tower(int n, char a, char b, char c){
    if(n == 1){
        cout << a << " -> " << c << endl;
    }else{
        tower(n - 1, a, c, b);
        cout << a << " -> " << c << endl;
        tower(n - 1, b, a, c);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    tower(n, '1', '2', '3');

    return 0;
}