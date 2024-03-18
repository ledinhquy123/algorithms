#include<bits/stdc++.h>
using namespace std;
class Inset{
    private:
        set<int> se;
    public:
        Inset(int a[], int n){
            for(int i = 0; i < n; i++){
                this->se.insert(a[i]);
            }
        }
        Inset(set<int> temp){
            this->se = temp;
        }
        Inset Union(Inset);
        friend ostream& operator << (ostream&, Inset);
};
ostream& operator << (ostream& out, Inset s){
    for(int x : s.se){
        cout << x << " ";
    }
    return out;
}
Inset Inset::Union(Inset a){
    set<int> temp;
    for(int x : this->se) temp.insert(x);
    for(int x : a.se) temp.insert(x);
    return temp; // Nó sẽ tự động nhảy vào hàm khởi tạo ở dòng 12
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    Inset s1(a, n);
    Inset s2(b, m);
    Inset s3 = s1.Union(s2);    
    cout << s3;

    return 0;
}