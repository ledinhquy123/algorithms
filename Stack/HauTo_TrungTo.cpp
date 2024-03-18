#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    stack<string> st;
    for(auto x : s){
        if(isalpha(x)) st.push(string(1, x));
        else{
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            string temp = "(" + b + x + a + ")";
            st.push(temp);
        }
    }
    cout << st.top();
    return 0;
}