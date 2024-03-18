#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 1;
int n, m, cnt;
vector<int> adj[maxn];
int color[maxn], parent[maxn];
bool used[maxn];
void inp(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cnt = 0;
	memset(used, false, sizeof(used));
	memset(color, 0, sizeof(color));
}
// kiem tra xem co the to mau c cho dinh u hay khong
bool check(int u, int c){
	for(int v : adj[u]){
		if(color[v] == c) return false;
	}
	return true;
}
// dung 1 mau c de to cho cang nhieu dinh cang tot
int Tomau(int c){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!color[i] && check(i, c)){
			color[i] = c;
			++cnt;
		}
	}
	return cnt;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	inp();
	int cnt = 0, temp = 0;
	while(cnt < n){
		cnt += Tomau(++temp);
	}
	for(int i = 1; i <= n; ++i) cout << color[i] << " ";

	return 0;
} 