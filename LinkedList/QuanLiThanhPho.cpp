#include<bits/stdc++.h>
using namespace std;
struct Tinh{
    int Ma;
    string Ten;
    float DienTich;
    long long DanSo;
};
struct Node{
    Tinh t;
    struct Node* next;
};
typedef struct Node* node;
node TaoNode(){
    Tinh t;
    cout << "Nhap ma: "; cin >> t.Ma; cin.ignore();
    cout << "Nhap ten: ";  getline(cin, t.Ten);
    cout << "Nhap dien tich: "; cin >> t.DienTich;
    cout << "Nhap dan so: "; cin >> t.DanSo;
    node temp = new Node();
    temp->t = t;
    temp->next = NULL;
    return temp;
}
int KichThuoc(node a){
    int cnt = 0;
    while(a != NULL){
        cnt++;
        a = a->next;
    }
    return cnt;
}
void InTinh(Tinh t){
    cout << "==========Infor==========\n";
    cout << "Ma: " << t.Ma << endl;
    cout << "Ten: " << t.Ten << endl;
    cout << "Dien tich: " << t.DienTich << endl;
    cout << "Dan so: " << t.DanSo << endl;
    cout << "==========End==========\n";
}
void DuyetDanhsach(node a){
    while(a != NULL){
        InTinh(a->t);
        cout << endl;
        a = a->next;
    }
}
void ThemDau(node &a){
    node temp = TaoNode();
    if(a == NULL) a = temp;
    else{
        temp->next = a;
        a = temp;
    }
}
void ThemCuoi(node &a){
    node temp = TaoNode();
    if(a == NULL) a = temp;
    else{
        node p = a;
        while(p->next != NULL){
            p = p->next;
        }
        p ->next = temp;
    }
}
void ThemBatKi(node &a, int pos){
    int n = KichThuoc(a);
    if(pos < 1 || pos > n + 1) return;
    if(pos == 1) ThemDau(a);
    else if(pos == n + 1) ThemCuoi(a);
    else{
        node p = a;
        for(int i = 1; i < pos - 1; i++){
            p = p->next;
        }
        node temp = TaoNode();
        temp->next = p->next;
        p->next = temp; 
    }
}
float TongDienTich(node a){
    float sum = 0;
    while(a != NULL){
        sum += a->t.DienTich;
        a = a->next;
    }
    return sum;
}
int ViTriTinhLonNhat(node a){
    int idex = 0, thutu = 0;
    float res = (int)(-1e9);
    while(a != NULL){
        thutu++;
        if(a->t.DienTich > res){
            res = a->t.DienTich;
            idex = thutu;
        }
        a = a->next;
    }
    return idex;
}
Tinh DanSoLonNhat(node a){
    long long res = -1e9;
    Tinh temp;
    while(a != NULL){
        if(a->t.DanSo > res){
            res = a->t.DanSo;
            temp = a->t;
        }
        a = a->next;
    }
    return temp;
}
void SapXepTheoMa(node &a){
    for(node p = a; p->next != NULL; p = p->next){
        node min = p;
        for(node j = p->next; j != NULL; j = j->next){
            if(j->t.Ma < min->t.Ma) min = j;
        }
        swap(p->t, min->t);
    }
}
void SapXepTheoDienTich(node &a){
    for(node i = a; i->next != NULL; i = i->next){
        node min = i;
        for(node j = i->next; j != NULL; j = j->next){
            if(j->t.DienTich < min->t.DienTich) min = j;
        }
        swap(i->t, min->t);
    }
}
void XoaTheoMa(node &a, int code){
    node truoc = a;
    node sau = NULL;
    while(truoc->t.Ma != code && truoc != NULL){
        sau = truoc;
        truoc = truoc->next;
    }
    if(truoc != NULL){
        sau->next = truoc->next;
    }else{
        cout << "Khong co thanh pho co ma nhu vua nhap!\n";
        return;
    }
}
void SuaTheoMa(node &a, int code){
    node truoc = a;
    node sau = NULL;
    while(truoc->t.Ma != code && truoc != NULL){
        sau = truoc;
        truoc = truoc->next;
    }
    if(truoc != NULL){
        cout << "Nhap thong tin tinh can chinh:\n";
        node temp = TaoNode();
        sau->next = temp;
        temp->next = truoc->next;
    }
}
int main(){
    node head = NULL;
    while(true){
        cout << "-----------MENU------------\n";
        cout << "1. Them dau\n";
        cout << "2. Them cuoi\n";
        cout << "3. Them bat ki\n";
        cout << "4. Duyet danh sach\n";
        cout << "5. Tong dien tich cac thanh pho\n";
        cout << "6. Vi tri cua node cua tinh co dien tich lon nhat\n";
        cout << "7. Thanh pho co dan so lon nhat\n";
        cout << "8. Sap xep danh sach theo ma tinh\n";
        cout << "9. Sap xep danh sach theo dien tich\n";
        cout << "10. Xoa theo ma thanh pho\n";
        cout << "11. Sua thanh pho theo ma\n";
        cout << "0. Thoat\n";
        int lc; cout << "Nhap lua chon: "; cin >> lc;
        if(lc == 1){
            ThemDau(head);
        }else if(lc == 2){
            ThemCuoi(head);
        }else if(lc == 3){
            int pos; cout << "Nhap vi tri can them: "; cin >> pos;
            ThemBatKi(head, pos);
        }else if(lc == 4){
            DuyetDanhsach(head);
        }else if(lc == 5){
            cout << "Tong dien tich: " << TongDienTich(head) << endl;
        }else if(lc == 6){
            cout << "Vi tri node: " << ViTriTinhLonNhat(head) << endl;  
        }else if(lc == 7){
            cout << "Thanh pho co dan so lon nhat:\n";
            Tinh x = DanSoLonNhat(head);
            InTinh(x);
        }else if(lc == 8){
            SapXepTheoMa(head);
        }else if(lc == 9){
            SapXepTheoDienTich(head);
        }else if(lc == 10){
            int code; cout << "Nhap ma thanh pho can xoa: "; cin >> code;
            XoaTheoMa(head, code);
        }else if(lc == 11){
            int code; cout << "Nhap ma thanh pho can sua: "; cin >> code;
            SuaTheoMa(head, code);
        }else
        if(lc == 0) break;
    }

    return 0;
}