#include<bits/stdc++.h>
using namespace std;
// chu y : ())( 2 dau ngoac quay lung lai voi nhau
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    stack<char> st;
    int ans = 0; // dem so thao tac
    for(auto x : s){
        if(x == '(') st.push(x);
        else{
            if(st.empty() && x == ')'){
                ++ans;
                st.push('(');
            }else{
                st.pop();
            }
        }
    }
    cout << st.size() / 2 + ans;
    return 0;
}