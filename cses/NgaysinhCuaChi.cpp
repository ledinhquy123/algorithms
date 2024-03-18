#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 11;
int ok;
void Sinh(string &s){
    int i = s.length() - 1l;;
    while(i >= 0 && s[i] == '2'){
        s[i] = '0';
        --i;
    }
    if(i == -1) ok = 0;
    else s[i] = '2';
}
bool check(string s){
    string ngay = s.substr(0, 2);
    if(ngay[0] == '0' && ngay[1] == '0') return false;
    string thang = s.substr(2, 2);
    if(thang[0] == '0' && thang[1] == '0') return false;
    string nam = s.substr(4);
    if(nam[0] == '0') return false;
    return thang[1] == '2' && thang[0] == '0';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s = "00000000";
    ok = 1;
    int cnt = 0;
    while(ok){
        if(check(s)){
            string temp = s;
            temp.insert(temp.begin() + 2, '/');
            temp.insert(temp.begin() + 5, '/');
            ++cnt;
            cout << temp << endl;
        }
        Sinh(s);
    }
    cout << cnt;
    return 0;
}