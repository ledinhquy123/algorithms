#include<bits/stdc++.h>
using namespace std;

// Operator overloading
// << >> 
// cout : ostream
// cin : istream
class SinhVien{
    private:
        string id, ten, ns;
        double gpa;
    public:
        friend istream& operator >> (istream& in, SinhVien &a); // nap chong nhap
        friend ostream& operator << (ostream& out, SinhVien a); // nap chong in
        // bool operator < (SinhVien a); // nap chong so sanh sinh vien hien tai voi sinh vien khac
        friend bool operator < (SinhVien a, SinhVien b); // so sanh 2 sinh vien

};
// bool SinhVien::operator < (SinhVien a){
//     return this->gpa < a.gpa;
// }
bool operator < (SinhVien a, SinhVien b){   
    return a.gpa < b.gpa;
}
istream& operator >> (istream& in, SinhVien &a){
    cout << "Nhap id: "; in >> a.id; cin.ignore();
    cout << "Nhap ten: "; getline(in, a.ten);
    cout << "Nhap ns: "; in >> a.ns;
    cout << "Nhap diem: "; in >> a.gpa;
    return in;
}

ostream& operator << (ostream& out, SinhVien a){
    out << a.id << " " << a.ten << " " << a.ns << " " << fixed << setprecision(2) << a.gpa << endl;
    return out;
}

class SoPhuc{
    private:
        int thuc, ao;
    public:
        friend istream& operator >> (istream& in, SoPhuc &);
        friend ostream& operator << (ostream& out, SoPhuc );
        SoPhuc operator + (SoPhuc another);
        // friend SoPhuc operator + (SoPhuc a, SoPhuc b);
        SoPhuc operator - (SoPhuc);
        bool operator == (SoPhuc);
};
istream& operator >> (istream &in, SoPhuc &a){
    cout << "Nhap phan thuc: "; in >> a.thuc;
    cout << "Nhap phan ao: "; in >> a.ao;
}
ostream& operator << (ostream &out, SoPhuc a){
    cout << a.thuc << " + " << a.ao << "i" << endl;
}
SoPhuc SoPhuc::operator + (SoPhuc a){
    SoPhuc tong;
    tong.thuc = this->thuc + a.thuc;
    tong.ao = this->ao + a.ao;
    return tong;
}
bool SoPhuc::operator == (SoPhuc another){
    return this->ao == another.ao && this->thuc == another.thuc;
}
int main(){
    // int n; cout << "Nhap so luong sinh vien: "; cin >> n;
    // SinhVien a[n];
    // for(int i = 0; i < n; i++){
    //     cin >> a[i];
    // }
    // sort(a, a + n); // thuong se dung comperator nhung khi da nap cong toan tu < thi sort mac dinh theo tang dan
    // for(int i = 0; i < n; i++){
    //     cout << a[i];
    // }
    SoPhuc x, y;
    cin >> x >> y;
    if(x == y) cout << "YES";
    else cout << "NO";

    return 0;
}