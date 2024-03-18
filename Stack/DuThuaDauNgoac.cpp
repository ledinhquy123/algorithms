#include<bits/stdc++.h>
using namespace std;
bool check(char c){
	return (c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^');
}
bool solve(string s){
	stack<char> st;
	for(char x : s){
		if(x != ')') st.push(x);
		else{
			bool ok = true;
			while(st.top() != '('){
				if(check(st.top())){
					ok = false;
				}
				st.pop();
			}
			if(ok) return true;
			st.pop();
		}
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	if(solve(s)) cout << "YES";
	else cout << "NO";

	return 0;
}