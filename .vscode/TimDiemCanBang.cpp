#include <bits/stdc++.h> 
using namespace std; 
using ll = long long;
int main(){     
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        bool ok = true;
        int a[n];
        ll sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        ll SumLeft = 0;
        for(int i = 0; i < n; i++){
            sum -= a[i];
            if(sum == SumLeft){
                cout << i << " ";
                ok = false;
            }else SumLeft += a[i]; 
        }
        if(ok) cout << "-1";
        cout << endl;
    }
 
    return 0;
}