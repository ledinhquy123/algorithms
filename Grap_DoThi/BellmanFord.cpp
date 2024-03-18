#include<bits/stdc++.h>
using namespace std;
// bellman ford : dùng cho đồ thị có trọng số âm nhưng không được có chu trình âm (tim duong di ngan nhat)
// Tương tu dijkstra nhưng chỉ dùng cho đồ thị có hướng 
// Djkstra dùng cho cả vô hướng và có hướng
int n, m, s;
struct canh{
    int x, y, w;
};
vector<canh> e;
void Nhap(){
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        e.push_back({x, y, w});
    }
}
void BellmanFord(int u){
    vector<int> d(n + 1, 1e9);
    d[u] = 0;
    // Chu y chi duyet den n - 1
    for(int i = 1; i <= n - 1; i++){
        // Duyet tung canh 1 cua do thi - relax
        for(int j = 0; j < m; j++){
            if(d[e[j].x] != 1e9){
                // if(d[e[j].y] < d[e[j].x] + e[j].w){
                    // Co chu trinh am
                    d[e[j].y] = min(d[e[j].y], d[e[j].x] + e[j].w);
                // }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << d[i] << ' ';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nhap();
    BellmanFord(s);

    return 0;
}