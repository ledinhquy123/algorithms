#include<bits/stdc++.h>
using namespace std;
int UuTien(char c){
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    stack<char> st;
    string res = "";
    for(char x : s){
        if(isalpha(x)) res += x;
        else if(x == '(') st.push(x);
        else if(x == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() && UuTien(x) <= UuTien(st.top())){
                res += st.top();
                st.pop();
            }
            st.push(x);
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    cout << res;
    return 0;
}
