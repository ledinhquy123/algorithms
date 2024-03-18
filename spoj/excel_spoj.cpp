#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string solve(int x){
    string ans = "";
    while(1){
        if(x == 0) break;
        x--;
        char c = 'A' + x % 26;
        x /= 26;
        ans = c + ans; 
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        char c;
        int x, y;
        cin >> c >> x >> c >> y;
        if(!x && !y) return 0;
        cout << solve(y) << x << endl;
    }
    

    return 0;
}