#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
// int a[10001][10001] : luu ma tran ke
// vector<pair<int, int>> edge : luu danh sach canh
// vector<int> ke[10001] : luu danh sach ke
vector<int> ke[1001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        // co huong thi tuong tu bo dong 17 di
        ke[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        cout << i << " : ";
        sort(ke[i].begin(), ke[i].end());
        for(auto x : ke[i]) cout << x << " ";
        cout << endl;
    }
    return 0;
}