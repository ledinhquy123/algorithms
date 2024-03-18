#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct job{
    int id, deadline, profit;
};
int main(){
    int n; cin >> n;
    job a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i].id >> a[i].deadline >> a[i].profit;
    }
    sort(a, a + n, [](job x, job y)->bool{
        return x.profit > y.profit;
    });
    int used[n + 1];
    ll res = 0;
    memset(used, 0, sizeof(used));
    for(int i = 0; i < n; i++){
        while(used[a[i].deadline] && a[i].deadline > 0) --a[i].deadline;
        if(a[i].deadline > 0 && used[a[i].deadline] == 0){
            res += a[i].profit;
            used[a[i].deadline] = 1;
        }
    }
    cout << res;

    return 0;
}