#include<bits/stdc++.h>
using namespace std;
// Từ inorder, preorder sang postorder
struct node{
    int val;
    node *left, *right;
    node(int x){
        val = x;
        left = right = NULL;
    }
};
void MakeNode(node *root, int u, int v, char c){
    if(c == 'L'){
        root->left = new node(v);
    }else root->right = new node(v);
}
void InsertNode(node *root, int u, int v, char c){
    if(root == NULL) return;
    if(root->val == u){
        MakeNode(root, u, v, c);
    }else{ 
        InsertNode(root->left, u, v, c);
        InsertNode(root->left, u, v, c);
    }
}
int Find(int in[], int n, int x){
    for(int i = 0; i < n; i++){
        if(in[i] == x) return i;
    }
    return -1;
}
void Postorder(int in[], int pre[], int n){
    int root = Find(in, n, pre[0]);
    if(root != 0){
        Postorder(in, pre + 1, root);
    }
    if(root != n - 1){
        Postorder(in + root + 1, pre + root + 1, n - root - 1);
    }
    cout << pre[0] << " ";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int pre[n], in[n];
    for(int i = 0; i < n; i++) cin >> pre[i];
    for(int i = 0; i < n; i++) cin >> in[i];
    Postorder(in, pre, n);

    return 0;
}