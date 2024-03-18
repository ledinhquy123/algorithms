#include <bits/stdc++.h>
using namespace std;
int n, x, a[100];
int ok[100], check;
void solve(int pos, int sum, int cnt){
	if(sum == x){
		cout << "[";
		for(int i = 0; i < cnt; i++){
			if(i != cnt - 1) cout << ok[i] << " ";
			else cout << ok[i];
		}
		check = 1;
		cout << "] ";
		return;
	} 
	for(int i = pos; i < n; i++){
		if(sum + a[i] <= x){
			ok[cnt] = a[i];
			solve(i, sum + a[i], cnt + 1);
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> x;
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		check = 0;
		solve(0, 0, 0);
		if(check) cout << endl;
		else cout << "-1\n";
	}
	return 0;
}