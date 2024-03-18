#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    stack<int> st;
    // Tim phan tu lon hon dau tien nam ben phai cua a[i]
    for(int i = 0; i < n; i++){
        if(st.empty()) st.push(i);
        else{
            while(!st.empty() && a[i] > a[st.top()]){
                b[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        b[st.top()] = -1;
        st.pop();
    }
    // Tim phan tu nho hon dau tien nam ben phai cua a[i]
    for(int i = 0; i < n; i++){
        if(st.empty()) st.push(i);
        else{
            while(!st.empty() && a[i] < a[st.top()]){
                c[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        c[st.top()] = -1;
        st.pop();
    }
    for(int i = 0; i < n; i++){
        if(b[i] == -1 || c[b[i]] == -1) cout << "-1 ";
        else cout << a[c[b[i]]] << " ";
    }

    return 0;
}