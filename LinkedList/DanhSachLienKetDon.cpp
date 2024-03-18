#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node* next;
};
typedef struct Node* node;

//cap phat dong mot node moi voi du lieu la so nguyen x
node MakeNode(int x){
	node temp = new Node();
	temp->data = x;
	temp->next = NULL;
	return temp;
}
//Kiem tra rong
bool empty(node a){
	return a == NULL;
}

//Dem so luong
int Size(node a){
	int cnt = 0;
	while(a != NULL){
		++cnt;
		a = a->next; //gan dia chi cua node tiep theo cho node hien tai
	}
	return cnt;
}

//Them 1 phan tu vao dau danh sach lien ket
void Insertfirst(node &a, int x){
	node temp = MakeNode(x);
	if(a == NULL){
		a = temp;
	}else{
		temp->next = a;
		a = temp;
	}
}
// void InsertFirst1(node *a, int x){
// 	node temp = MakeNode(x);
// 	if(*a == NULL){
// 		*a = temp;
// 	}else{
// 		temp->next = *a;
// 		*a = temp;
// 	}
// }

//Them 1 phan tu vao cuoi danh sach
void InsertLast(node &a, int x){
	node temp = MakeNode(x);
	if(a == NULL){
		a = temp;
	}else{
		node p = a;
		while(p->next != nullptr){
			p = p->next;
		}
		p->next = temp;
	}
}

//Them vao vi tri bat ki
void InsertMiddle(node &a, int x, int pos){
	int n = Size(a);
	if(pos < 1 || pos > n + 1){
		cout << "Vi tri k hop le\n";
		return;
	}
	if(pos == 1){
		Insertfirst(a, x);
		return;
	}
	else if(pos == n + 1){
		InsertLast(a, x); 
		return;
	}
	node p = a;
	for(int i = 1; i < pos - 1; i++){
		p = p->next;
	}
	node temp = MakeNode(x);
	temp->next = p->next;
	p->next = temp;
}

//Xoa phan tu o dau
void DeleteFirst(node &a){
	if(a == NULL){
		cout << "Danh sach trong\n";
		return;
	}
	a = a->next;
}

//Xoa phan tu o cuoi
void DeleteLast(node &a){
	if(a == NULL){
		printf("Danh sach trong\n");
		return;
	}
	node p = a, truoc = NULL;
	while(p->next != NULL){
		truoc = p;
		p = p->next;
	}
	if(truoc == NULL){
		a = NULL;
	}else{
		truoc->next = NULL;
	}
}

//Xoa o giua
void DeleteMiddle(node &a, int pos){
	int n = Size(a);
	if(pos < 1 || pos > n + 1){
		cout << "Vi tri khong hop le!\n";
		return;
	}
	if(a == NULL){
		cout << "Danh sach trong\n";
		return;
	}
	else{
		node truoc = NULL, sau = a;
		for(int i = 1; i < pos; i++){
			truoc = sau;
			sau = sau->next;
		}
		if(truoc == NULL) a = a->next;//tuong tu xoa o dau
		else truoc->next = sau->next;
	}
}
void In(node a){
	while(a != NULL){
		cout << a->data << " ";
		a = a->next;
	}
}
void SapXep(node &a){
	for(node p = a; p->next != NULL; p = p->next){
		node min = p;
		for(node q = p->next; q != NULL; q = q->next){
			if(q->data < min->data) min = q;
		}
		// luu y la hoan vi cac gia tri cua cac node
		swap(p->data, min->data);
	}
}
// tim kiem trong dslk
// tim phan tu lon nhat, nho nhat trong danh sach
// tim phan tu la so nguyen to

int main(){
	node head = NULL;
	while(1){
		cout << "--------------MENU---------------\n";
		cout << "1. Chen phan tu vao dau danh sach\n";
		cout << "2. Chen phan tu vao cuoi danh sach\n";
		cout << "3. Chen phan tu vao giua danh sach\n";
		cout << "4. Xoa phan tu o dau danh sach\n";
		cout << "5. Xoa phan tu o cuoi danh sach\n";
		cout << "6. Xoa phan tu o giua danh sach\n";
		cout << "7. Duyet danh sach\n";
		cout << "8. Sap xep cac phan tu trong danh sach tang dan\n";
		cout << "----------------------------------\n";
		cout << "Nhap lua chon: ";
		int lc; cin >> lc;
		if(lc == 1){
			cout << "Nhap gia tri can chen:"; int x; cin >> x;
			Insertfirst(head, x);
		}else if(lc == 2){
			cout << "Nhap gia tri can chen: "; int x; cin >> x;
			InsertLast(head, x);
		}else if(lc == 3){
			cout << "Nhap gia tri, vi tri can chen: ";
			int x, pos; cin >> x >> pos;
			InsertMiddle(head, x, pos);
		}else if(lc == 4){
			DeleteFirst(head);
		}else if(lc == 5){
			DeleteLast(head);
		}else if(lc == 6){
			cout << "Nhap vi tri can xoa: "; int pos; cin >> pos;
			DeleteMiddle(head, pos);
		}else if(lc == 7){
			In(head);
			cout << endl;
		}else if(lc == 8){
			SapXep(head);
		}else if(lc == 0) break;
	}
	return 0;
}