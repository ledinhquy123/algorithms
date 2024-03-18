#include<bits/stdc++.h>
using namespace std;
// Class : lop
// Thuoc tinh : attribute
// Phuong thuc : method, behavier 
// Doi tuong : object
// Ham tao: constructor
// Ham huy: destructor
// This pointer
// setter, getter

// Dong goi : encapsulation
// Access modifier:
// - Private
// - Public
// - Protected
// - Static
// - Friend function, friend class : khong phai thanh vien cua lop hien tai nhung van truy cap vao tp private


// sv001->sv002->sv003
class SinhVien;
class giaovien;

class SinhVien{
    friend class giaovien;
    private:
        string id, ten, ns;
        double gpa;
        static int dem; // khong duoc gan cho bien static va bien static se dung chung cho ca cac doi tuong
    public:
        SinhVien(); // constructor neu khong xay dung cung co san
        SinhVien(string ,string, string, double); // constructor
        void Nhap();
        void In();
        double getgpa(); // dung getter lay ra gpa
        double getid();
        string getten();
        string getns();
        void setgpa(double); // dung setter de gan gia tri cho thuoc tinh
        void tangdem();
        int getdem();
        friend void inthongtin(SinhVien); // co the truy cap vao private
        friend void chuanhoa(SinhVien&); 
        ~SinhVien(); // ham huy
};

class giaovien{
    private:
        string khoa;
    public:
        void update(SinhVien&);
};

void giaovien::update(SinhVien &x){
    x.gpa = 3.2;
}
void inthongtin(SinhVien x){
    cout << x.ten << " " << x.id << endl;
}
void chuanhoa(SinhVien &a){
    string res = "";
    stringstream ss(a.ten);
    string token;
    while(ss >> token){
        res += toupper(token[0]);
        for(int i = 1; i < token.length(); i++){
            res += tolower(token[i]);
        }
        res += " ";
    }
    res.erase(res.length() - 1);
    a.ten = res;
}
int SinhVien::dem = 0;
void SinhVien::tangdem(){
    dem++;
}
int SinhVien::getdem(){
    return dem;
}
SinhVien::SinhVien(){
    // cout << "Ham khoi tao duoc goi\n";
    ten = "";
    gpa = 0;
}
SinhVien::SinhVien(string id, string ten, string ns, double gpa){
    cout << "Ham khoi tao co tham so duoc goi\n";
    // Co the dung con tro this de chi ro thuoc tinh thuoc lop sinh vien
    this->id = id;
    this->ten = ten;
    this->ns = ns;
    this->gpa = gpa; 
}
SinhVien::~SinhVien(){
    // cout << "Doi tong duoc huy tai day\n";
}
void SinhVien::Nhap(){
    // cout << "Nhap id: "; cin >> id; cin.ignore();
    dem++;
    this->id = "SV" + string(3-to_string(dem).length(), '0') + to_string(dem);
    cout << "Nhap ten: "; getline(cin, ten);
    cout << "Nhap ns: "; cin >> ns; 
    cout << "Nhap diem: "; cin >> gpa;
    cin.ignore(); 
}
void SinhVien::In(){
    cout << id << " " << ten << " " << ns << " " << fixed << setprecision(2) << gpa << endl;
}
double SinhVien::getgpa(){
    return this->gpa;
}
bool comp(SinhVien a, SinhVien b){
    return a.getgpa() > b.getgpa();
}
void SinhVien::setgpa(double gpa){
    this->gpa = gpa;
}
int main(){
    // SinhVien x("1", "Phan Hong Nhung", "28-02-2003", 4.0);
    SinhVien x;
    x.Nhap();
    giaovien y;
    y.update(x);
    x.In();

    return 0;
}