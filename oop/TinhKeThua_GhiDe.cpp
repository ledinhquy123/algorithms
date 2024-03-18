#include<bits/stdc++.h>
using namespace std;
// Base class : lop cha
// Derived class : lop con

class Person{
    private:
        string name;
        string address;
    public:
        Person(string name, string address){
            this->name = name;
            this->address = address;
        }
        void nhap(){
            getline(cin, name);
            getline(cin, address);
        }
        string getname(){
            return this->name;
        }
        string getaddress(){
            return this->address;
        }
        void setname(string name){
            this->name = name;
        }
        void setaddress(string address){
            this->address = address;
        }
        void in(){
            cout << name << " " << address << " ";
        }
};

// Neu la private thi moi thuoc tinh cua lop cha se laf private cua lop con
// Neu la protected thi moi thuoc tinh public cua lop cha se thanh protected cua lop con (private cx giong protected deu k the truy cap o ngoai lop)

class Student : public Person{
    private:
        float gpa;
    public:
    // Cu Phap ham khoi tao trong class con
        Student(string name, string address, float gpa) : Person(name, address){
            this->gpa = gpa;
        }
        // Function overriding
        float getgpa(){
            return this->gpa;
        }
        void setgpa(float gpa){
            this->gpa = gpa;
        }
        // goi la ghi de : overide
        // Khong the truy cap vao tp private cua person ma phai thong qua ham setter, getter
        void in(){
            // cout << getname() << " " << getaddress() << fixed << setprecision(2) << gpa << endl;
            Person::in();
            cout << fixed << setprecision(2) << gpa << endl;
        }
        void nhap(){
            Person::nhap();
            cin >> gpa;
        }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Student s("Phan Hong Nhung", "Can Tho", 3.2);
    // s.Person::nhap();
    // s.Person::in();


    return 0;
}
// Trong trường hợp class con không có hàm nhập, xuất thì khi gọi ở hàm main 
// thì sẽ mặc định gọi hàm ở class cha còn nếu đã định nghĩa trong class con thì nó sẽ gọi trong class con