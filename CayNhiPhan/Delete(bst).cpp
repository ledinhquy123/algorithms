#include<bits/stdc++.h>
using namespace std;
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
    if(x < root->val) root->left = Insert(root->left, x);
    if(x > root->val) root->right = Insert(root->right, x);
    return root;
}
// Tìm node con nhỏ nhất thuộc cấy con bên phải của node root
node* findMin(node *root){
    node* temp = root;
    while(temp != NULL && temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
node* deleteNode(node *root, int x){
    if(root == NULL) return root;
    if(x < root->val){
        root->left = deleteNode(root->left, x);
    }else if(x > root->val){
        root->right = deleteNode(root->right, x);
    }else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if(root->left == NULL || root->right == NULL){
            if(root->left == NULL){
                // co node con ben phai
                node *temp = root->right;
                delete root;
                return temp;
            }else{
                // co node con ben trai
                node *temp = root->left;
                delete root;
                return temp;
            }
        }else{
            // co node con o ca ben trai va ben phai
            node *temp = findMin(root->right); // tim phan tu nho nhat o ben phai
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root;
}
void Inorder(node *root){
    if(root == NULL) return;
    Inorder(root->left);
    if(root->val) cout << root->val << " ";
    Inorder(root->right);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    node *root = NULL;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        root = Insert(root, x);
    }
    int x; cin >> x;
    deleteNode(root, x);
    Inorder(root);

    return 0;
}