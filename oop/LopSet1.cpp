#include<bits/stdc++.h>
using namespace std;
using ld = long double;
class InSet{
    private:
        set<int> se;
    public:
        InSet(int a[], int n){
            for(int i = 0; i < n; i++){
                this->se.insert(a[i]);
            }
        }   
        // InSet(set<int> temp){
        //     this->se = temp;
        // }
        InSet intersection(InSet);
        friend ostream& operator << (ostream&, InSet);
};
ostream& operator << (ostream& out, InSet s){
    for(int x : s.se){
        out << x << " ";
    }
    return out;
}
InSet InSet::intersection(InSet a){
    // set<int> temp;
    InSet temp({}, 0);
    for(int x : this->se){
        if(a.se.find(x) != a.se.end()) temp.se.insert(x);   
    }
    return temp;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    InSet s1(a, n);
    InSet s2(b, m);
    InSet s3 = s1.intersection(s2);
    cout << s3;

    return 0;
}