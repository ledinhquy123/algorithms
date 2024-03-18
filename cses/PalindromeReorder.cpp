#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    int pos[26] = {0}, c1 = 0;
    for(char x : s) pos[x - 'A']++;
    for(int i = 0; i < 26; i++){
        if(pos[i] & 1) ++c1;
    }
    if(c1 > 1){
        cout << "NO SOLUTION";
        return 0;
    }
    string t;
    int ans = 0;
    for(int i = 0; i < 26; ++i){
        if(pos[i] & 1) ans = i;
    }
    if(pos[ans]){
        for(int i = 0; i < pos[ans]; ++i) t += char(ans + 'A');
        pos[ans] = 0;
    }
    
    string res;
    for(int i = 0; i < 26; i++){
        if(pos[i]){
            for(int j = 0; j < pos[i] / 2; j++){
                res += char(i + 'A');
            }
            pos[i] = 0;
        }
    }
    string temp = res;
    reverse(temp.begin(), temp.end());
    cout << res + t + temp;

    return 0;
}