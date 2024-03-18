#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node *left, *right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};
void MakeNode(node *root, int u, int v, char c){
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}
void InsertNode(node *root, int u, int v, char c){
    if(root == NULL) return;
    if(root->val == u){
        MakeNode(root, u, v, c);
    }else{
        InsertNode(root->left, u, v, c);
        InsertNode(root->right, u, v, c);
    }
}
int NodeLa(node *root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    return NodeLa(root->left) + NodeLa(root->right);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    node *root = NULL;
    for(int i = 0; i < n; i++){
        int u, v; char c;
        cin >> u >> v >> c;
        if(root == NULL){
            root = new node(u);
            MakeNode(root, u, v, c);
        }else{
            InsertNode(root, u, v, c);
        }
    }
    cout << NodeLa(root);
  
    return 0;
}