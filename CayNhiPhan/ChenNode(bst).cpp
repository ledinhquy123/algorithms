#include<bits/stdc++.h>
using namespace std;
// Binary search tree: cay nhi phan tim kiem
// Tất cả các node thộc cây con bên trái phải nhỏ node gốc
// Tất cả các node thuộc cây con bên phải phải lớn hơn node gốc
// Cây con bên trái, bên phải cũng phải là cây nhị phân tìm kiếm
// search, insert, delete
// left < root < right
struct node{
	int val;
	node *left, *right;
	node(int x){
		val = x;
		left = right = NULL;
	}
};
node* Insert(node *root, int x){
	if(root == NULL) return new node(x);
	if(x < root->val){
		root->left = Insert(root->left, x);
	}else{
		root->right = Insert(root->right, x);
	}
	return root;
}
void Inorder(node *root){
	if(root == NULL) return;
	Inorder(root->left);
	cout << root->val << " ";
	Inorder(root->right);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	node* root = NULL;
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		root = Insert(root, x);
	}
	Inorder(root);

	return 0;
}