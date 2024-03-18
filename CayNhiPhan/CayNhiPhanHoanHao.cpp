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
int cnt, ans;
// check cung muc
bool check1(node* root, int pre){
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL){
        cnt++;
        if(cnt == 1){
            ans = pre;
            return true;
        }
        else return ans == pre;
    }
    return check1(root->left, pre + 1) && check1(root->right, pre + 1);
}

// bool check1(node* root, int h, int &maxh){
//     if(root == NULL) return true;
//     if(root->left == NULL && root->right == NULL){
//         if(maxh == 0){
//             maxh = h;
//             return true;
//         }else{
//             return h == maxh;
//         }
//     }
//     return check1(root->left, h + 1, maxh) && check1(root->right, h + 1, maxh);
// }
// check day du
bool check2(node* root){
    if(root == NULL) return true;
    if(root->right == NULL && root->left == NULL) return true;
    if(root->right != NULL && root->left != NULL){
        return check2(root->left) && check2(root->right);
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    node *root = NULL;
    for(int i = 0; i < n; i++){
        int u, v; char c; cin >> u >> v >> c;
        if(root == NULL){
            root = new node(u);
            MakeNode(root, u, v, c);
        }else{
            InsertNode(root, u, v, c);
        }
    }
    int maxh = 0;
    if(check1(root, 0) && check2(root)) cout << "YES";
    else cout << "NO";

    return 0;
}