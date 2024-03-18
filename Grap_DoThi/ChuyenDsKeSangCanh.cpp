#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
using ll = long long;
vector<pair<int, int>> edge; // luu danh sach canh
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++){
        string s; getline(cin, s);
        stringstream ss(s);
        string temp;
        while(ss >> temp){
            if(stoi(temp) > i) cout << i << " " << temp << endl;
        }
    }

    return 0;
}
