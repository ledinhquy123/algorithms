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
void dfs(node *root){
    stack<node*> st1, st2;
    st1.push(root);
    while(!st1.empty() || !st2.empty()){
        while(!st1.empty()){
            node* temp = st1.top(); st1.pop();
            cout << temp->val << " ";
            if(temp->right != NULL) st2.push(temp->right);
            if(temp->left != NULL) st2.push(temp->left);
        }
        while(!st2.empty()){
            node* temp = st2.top(); st2.pop();
            cout << temp->val << " ";
            if(temp->left != NULL) st1.push(temp->left);
            if(temp->right != NULL) st1.push(temp->right);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    node* root = NULL;
    for(int i = 0; i < n; i++){
        int u, v; char c; cin >> u >> v >> c;
        if(root == NULL){
            root = new node(u);
            MakeNode(root, u, v, c);
        }else{
            InsertNode(root, u, v, c);
        }
    }
    dfs(root);

    return 0;
}