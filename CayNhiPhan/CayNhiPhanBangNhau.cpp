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
bool check(node* root1, node* root2){
    if(root1 == NULL && root2 == NULL) return true;
    else if(root1 != NULL && root2 != NULL){
        return root1->val == root2->val && check(root1->left, root2->left) && check(root1->right, root2->right);  
    } 
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int n; cin >> n;
    node *root1 = NULL;
    for(int i = 0; i < n; i++){
        int u, v; char c; cin >> u >> v >> c;
        if(root1 == NULL){
            root1 = new node(u);
            MakeNode(root1, u, v, c);
        }else InsertNode(root1, u, v, c);
    }
    int m; cin >> m;
    node *root2 = NULL;
    for(int i = 0; i < m; i++){
        int u, v; char c; cin >> u >> v >> c;
        if(root2 == NULL){
            root2 = new node(u);
            MakeNode(root2, u, v, c);
        }else InsertNode(root2, u, v, c);
    }
    if(n != m){
        cout << "NO"; 
    }else{
        if(check(root1, root2)) cout << "YES";
        else cout << "NO";
    }

    return 0;
}