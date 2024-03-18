#include<bits/stdc++.h>
using namespace std;
// Xoa k tu giong nhau
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	int k; cin >> k;
	stack<pair<char, int>> st;
	for(char x : s){
		if(st.empty()) st.push({x, 1});
		else{
			char temp = st.top().first;
			if(temp == x){
				if(st.top().second + 1 == k){ // kiem tra xem da du k ki tu de xoa hay chua
					st.pop();
				}else{
					st.top().second++; // chu du thi tang tan xuat len 1 don vi
				}
			}else st.push({x, 1});
		}
	}
	vector<char> res;
	while(!st.empty()){
		while(st.top().second--){
			res.push_back(st.top().first);
		}
		st.pop();
	}
	if(res.size()){
		reverse(res.begin(), res.end());
		for(auto x : res) cout << x;
	}else cout << "EMPTY";

	return 0;
}