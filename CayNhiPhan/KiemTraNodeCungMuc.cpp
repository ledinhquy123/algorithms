#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *left, *right;
    Node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};
void MakeNode(Node *root, int u, int v, char c){
    if(c == 'L'){
        root->left = new Node(v);
    }else root->right = new Node(v);
}
void InsertNode(Node *root, int u, int v, char c){
    if(root == NULL) return;
    if(root->val == u){
        MakeNode(root, u, v, c);
    }else{
        InsertNode(root->left, u, v, c);
        InsertNode(root->right, u, v, c);
    }
}
int cnt, ans;
bool check(Node *root, int pre){
    if(root == NULL) return true;
    if(root->right == NULL && root->left == NULL){
        cnt++;
        if(cnt == 1) ans = pre; // nut la dua tien gap
        else if(ans != pre) return false;
    }
    return check(root->left, pre + 1) && check(root->right, pre + 1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    Node *root = NULL;
    for(int i = 0; i < n; i++){
        int u, v; char c; cin >> u >> v >> c;
        if(root == NULL){
            root = new Node(u);
            MakeNode(root, u, v, c);
        }else{
            InsertNode(root, u, v, c);
        }
    }
    if(check(root, 0)) cout << "YES";
    else cout << "NO";

    return 0;
}