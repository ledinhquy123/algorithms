#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// XAY DUNG DANH SACH LIEN KET DON BANG STACK
struct Node{
    string data;
    Node* next;
};
typedef struct Node* node;  
bool Empty(node top){
    return top == NULL;
}
int GetSize(node top){
    int ans = 0;
    while(top != NULL){
        ++ans;
        top = top->next;
    }
    return ans;
}
node MakeNode(node &top, string x){
    node temp = new Node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}
void Push(node &top, string x){
    node temp = MakeNode(top, x);
    if(top == NULL){
        top = temp;
    }else{
        temp->next = top;
        top = temp;
    }
}
void Pop(node &top){
    if(top == NULL){
        cout << "Danh sach trong\n";
    }else{
        top = top->next;
    }
}
string getTop(node top){
    return top->data;
}
int main(){
    node top = NULL;
    string s; getline(cin, s);
    stringstream ss(s);
    string temp;
    while(ss >> temp){
        Push(top, temp);
    }
    while(!Empty(top)){
        cout << getTop(top) << ' ';
        Pop(top);
    }
    return 0;
}