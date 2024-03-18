#include<bits/stdc++.h>
using namespace std;
// Đếm số nút lá có mưc cao nhất
struct Node{
    int val;
    Node *right, *left;
    Node(int x){
        val = x;
        left = right = NULL;
    }
};
typedef Node node;
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
int hight(node* root){
    if(root == NULL) return 0;
    return 1 + max(hight(root->left), hight(root->right));
}
void bfs(node* root){
    int Max = hight(root);
    int cnt = 0;
    queue<pair<node*, int>> q;
    q.push({root, 1});
    while(!q.empty()){
        auto temp = q.front(); q.pop();
        if(temp.first->left == NULL && temp.first->right == NULL){
            if(temp.second == Max) ++cnt;
        }
        if(temp.first->left != NULL) q.push({temp.first->left, temp.second + 1});
        if(temp.first->right != NULL) q.push({temp.first->right, temp.second + 1});
    }
    cout << cnt;
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
    bfs(root);

    return 0;
}