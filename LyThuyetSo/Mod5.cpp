#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void solve(string s){
	int temp = 0;
	if(s.length() < 2) temp = s[0] - '0';
	else temp = 10 * (s[s.length() - 1] - '0') + (s[s.length() - 2] - '0');
	if(temp % 4 == 0) cout << "4\n";
	else cout << "0\n";
}
int main(){
	string s; cin >> s;
	solve(s);

	return 0;
}