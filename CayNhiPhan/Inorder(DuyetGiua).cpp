#include<bits/stdc++.h>
using namespace std;
// Cay nhi phan : Binary tree
struct Node{
    int val;
    Node *left, *right;
    Node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

void MakeNode(Node* root, int u, int v, char c){
    if(c == 'L'){
        root->left = new Node(v);
    }else{
        root->right = new Node(v);
    }
}

void InsertNode(Node* root, int u, int v, char c){
    if(root == NULL) return;
    if(root->val == u){
        MakeNode(root, u, v, c);
    }else{
        InsertNode(root->left, u, v, c);
        InsertNode(root->right, u, v, c);
    }
}

// Inorder: duyet giua
// Preorder: duyet truoc
// Postorder: duyet sau
void Inorder(Node* root){
    if(root == NULL) return;
    Inorder(root->left);
    cout << root->val << " ";
    Inorder(root->right);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        int u, v; char c;
        cin >> u >> v >> c;
        if(root == NULL){
            root = new Node(u);
            MakeNode(root, u, v, c);
        }else{
            InsertNode(root, u, v, c);
        }
    }
    Inorder(root);

    return 0;
}