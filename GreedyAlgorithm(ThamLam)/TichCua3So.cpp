#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n; cin >> n;
    set<int> se;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            se.insert(i);
            n /= i;
            if(se.size() == 2) break;
        }
    }    
    if(n == 1 || se.count(n) == 1 || se.size() <= 1) cout << "NO";
    else cout << "YES";

    return 0;
}