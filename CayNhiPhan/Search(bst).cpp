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
    if(x < root->val){
        root->left = Insert(root->left, x);
    }else root->right = Insert(root->right, x);
    return root;
}
bool check(node *root, int x){
    if(root == NULL) return false;
    if(root->val == x) return true;
    if(x < root->val) return check(root->left, x);
    return check(root->right, x);
}
// int ok;
// void Find(node *root, int x){
//     if(root == NULL) return;
//     if(root->val == x) ok = 1;
//     if(x < root->val) Find(root->left, x);
//     else Find(root->right, x);
// }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int a[n];
    node *root = NULL;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        root = Insert(root, a[i]);
    }
    int x; cin >> x;
    if(check(root, x)) cout << "YES";
    else cout << "NO";

    return 0;
}