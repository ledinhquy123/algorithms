#include<bits/stdc++.h>
using namespace std;
// next greater element
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int a[n], b[n]; // mang b de luu gia tri can tim
    for(int &x : a) cin >> x;
    stack<int> st;
    for(int i = 0; i < n; i++){
        if(st.empty()) st.push(i);
        else{
            while(!st.empty() && a[st.top()] < a[i]){
                b[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        b[st.top()] = -1;
        st.pop();
    }
    for(int x : b) cout << x << " ";

    return 0;
}