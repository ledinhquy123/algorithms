#include<bits/stdc++.h>
using namespace std;
class A{
    public:
        A(){
            cout << "Constructor lop A\n";
        }
        ~A(){
            cout << "Destructor cua A\n";
        }
        void xinchao(){
            cout << "Xin chao A\n";
        }
};
class B{
    public:
        B(){
            cout << "Constructer cua lop B\n";
        }
        ~B(){
            cout << "Destructor cua lop B\n";
        }
        void xinchao(){
            cout << "Xin chao B\n";
        }
};
class C : public B{
    public:
        C(){
            cout << "Constructor cua C\n";
        }
        ~C(){
            cout << "Destructor cua C\n";
        }
        void xinchao(){
            cout << "Xin chao C\n";
        }
};
class D : public A, public B{
    public:
        D(){
            cout << "Constructor cua D\n";
        }
        ~D(){
            cout << "Destructor cua D\n";
        }
        // void xinchao(){
        //     cout << "Ke thua tu A va B\n";
        // }
};
int main(){
    D obj;
    obj.A::xinchao();// Truyen pham vi moi biet cua lop nao
    


    return 0;
}