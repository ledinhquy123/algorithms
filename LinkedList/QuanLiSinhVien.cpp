#include<bits/stdc++.h>
using namespace std;
struct SinhVien{
    string name, id;
    double gpa;
};
struct SV{
    SinhVien s;
    struct SV* next;
};
typedef struct SV* sv;
sv MakeNode(){
    SinhVien x;
    cout << "Nhap thong tin sinh vien:\n";
    cout << "Nhap id: "; cin >> x.id; cin.ignore();
    cout << "Nhap ten: "; getline(cin, x.name);
    cout << "Nhap gpa: "; cin >> x.gpa;
    sv temp = new SV();
    temp->s = x;
    temp->next = NULL;
    return temp;
}
void InSinhVien(SinhVien x){
    cout << "----------Info----------\n";
    cout << "Id: " << x.id << endl;
    cout << "Ten: " << x.name << endl;
    cout << "Gpa: " << x.gpa << endl;
}
void In(sv a){
    cout << "Danh sach sinh vien:\n";
    while(a != NULL){
        InSinhVien(a->s);
        a = a->next;
    }
}
//Kiem tra rong
bool Empty(sv a){
    return a == NULL;
}
int Size(sv a){
    int cnt = 0;
    while(a != NULL){
        ++cnt;
        a = a->next;
    }
    return cnt;
}
void InsertFirst(sv &a){
    sv temp = MakeNode();
    if(a == NULL){
        a = temp;
    }else{
        temp->next = a;
        a = temp;
    }
}
void InsertLast(sv &a){
    sv temp = MakeNode();
    if(a == NULL){
        a = temp;
    }else{
        sv p = a;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}
void InsertMiddle(sv &a, int pos){
    int n = Size(a);
    if(pos < 1 || pos > n + 1){
        cout << "Vi tri khong hop le";
    }else{
        if(pos == 1) InsertFirst(a);
        else if(pos == n + 1) InsertLast(a);
        else{
            sv p = a;
            for(int i = 1; i < pos - 1; i++){
                p = p->next;
            }
            sv temp = MakeNode();
            temp->next = p->next;
            p->next = temp;
        }
    }
}
void DeleteFirst(sv &a){
    if(a == NULL){
        cout << "Danh sach trong";
        return;
    }
    a = a->next;
}
void DeleteLast(sv &a){
    if(a == NULL){
        cout << "Danh sach rong";
        return;
    }
    sv truoc = a, sau = NULL;
    while(truoc->next != NULL){
        sau = truoc;
        truoc = truoc->next;
    }
    if(sau == NULL){
        a = a->next;
    }else{
        sau->next = truoc->next;
    }
}
void DeleteMiddle(sv &a, int pos){
    int n =Size(a);
    if(pos < 1 || pos > n + 1){
        cout << "Vi tri khong hop le";
        return;
    }
    if(a == NULL){
        cout << "Danh sach trong";
        return;
    }
    sv truoc = a, sau = NULL;
    for(int i = 1; i < pos; i++){
        sau = truoc;
        truoc = truoc->next;
    }
    if(sau == NULL){
        a = a->next;
    }else sau->next = truoc->next;
}
void SapXepGpa(sv &a){
    for(sv p = a; p->next != NULL; p = p->next){
        sv pos = p;
        for(sv q = p->next; q != NULL; q = q->next){
            if(q->s.gpa < pos->s.gpa) pos = q;
        }
        swap(p->s, pos->s);
    }
}
int main(){
    sv head = NULL;
    while(1){
        cout << "---------MENU--------\n";
        cout << "1. Chen dau\n";
        cout << "2. Chen cuoi\n";
        cout << "3. Chen giua\n";
        cout << "4. Xoa dau\n";
        cout << "5. Xoa cuoi\n";
        cout << "6. Xoa giua\n";
        cout << "7. In\n";
        cout << "8. Sap xep theo gpa\n";
        cout << "0. Ket thuc\n";
        cout << "Nhap lua chon: ";
        int lc; cin >> lc;
        if(lc == 1){
            InsertFirst(head);
        }else if(lc == 2){
            InsertLast(head);
        }else if(lc == 3){
            int pos; cout << "Nhap vi tri can chen: "; cin >> pos;
            InsertMiddle(head, pos);
        }else if(lc == 4){
            DeleteFirst(head);
        }else if(lc == 5){
            DeleteLast(head);
        }else if(lc == 6){
            int pos; cout << "Nhap vi tri can xoa: "; cin >> pos;
            DeleteMiddle(head, pos);
        }else if(lc == 7){
            In(head);
        }else if(lc == 8){
            SapXepGpa(head);
        }else if(lc == 0) break;
    }
    return 0;
}
// tim kiếm sinh viên theo tên, mã,...