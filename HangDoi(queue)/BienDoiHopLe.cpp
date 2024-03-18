#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int prime[10001];
void Sang(){
    for(int i = 0; i <= 10000; i++){
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for(int i = 2; i <= sqrt(10000); i++){
        if(prime[i]){
            for(int j = i * i; j <= 10000; j += i){
                prime[j] = 0;
            }
        }
    }
}
char ans[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int bfs(int s, int t){
    queue<pair<int, int>> q;
    q.push({s, 0});
    set<int> se;
    se.insert(s);
    while(!q.empty()){
        auto temp = q.front(); q.pop();
        int v = temp.first; int d = temp.second;
        if(v == t) return d;
        string str = to_string(v);
        for(int i = 0; i < 4; i++){
            char y = str[i];
            for(char x : ans){
                if(str[i] != x){
                    str[i] = x;
                    int value = stoi(str);
                    if(value >= 1000 && prime[value]){
                        if(!se.count(value)){
                            q.push({value, d + 1});
                            se.insert(value);
                        }
                    }
                }
            }
            str[i] = y;
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    Sang();
    while(t--){
        int s, t; cin >> s >> t;
        cout << bfs(s, t) << endl;
    }

    return 0;
}