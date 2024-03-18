#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> v;
    v.push_back(a[0]);
    for(int i = 1; i < n; i++){
        auto it = lower_bound(v.begin(), v.end(), a[i]);
        if(it != v.end()){
            *it = a[i];
        }else v.push_back(a[i]);
    }
    cout << v.size();
    return 0;
}