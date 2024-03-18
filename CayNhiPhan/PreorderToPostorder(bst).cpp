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
    else root->right = Insert(root->right, x);
    return root;
}
void Postorder(node *root){
    if(root == NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->val;
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
    Postorder(root);
    return 0;
}