#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    stack<int> st;
    for(char x : s){
        if(isdigit(x)) st.push(x - '0');
        else{
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            int n = 0;
            if(x == '+') n = b + a;
            else if(x == '-') n = b - a;
            else if(x == '*') n = b * a;
            else if(x == '/') n = b / a;
            st.push(n);
        }
    }
    cout << st.top();
    return 0;   
}