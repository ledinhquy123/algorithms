#include<bits/stdc++.h>
using namespace std;
const int mod = (int)(1e9 + 7);
using ll = long long;
int n, a[21], x[21];
vector<string> v;
void Try(int pos, int k){
    if(k >= 2){
        string temp = "";
        for(int h = 0; h < k; h++){
            temp += to_string(x[h]) + " ";
        }
        v.push_back(temp);
    }
    for(int i = pos; i < n; i++){
        if(a[i] > x[k - 1]){
            x[k] = a[i];
            Try(i + 1, k + 1);
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    Try(0, 0);
    sort(v.begin(), v.end());
    for(auto x : v){
        cout << x << endl;
    }
    return 0;
}