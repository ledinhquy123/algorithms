#include<bits/stdc++.h>
using namespace std;
// XAY DUNG QUEUE BANG DSLKD
struct Node{
    int data;
    Node* next;
};
typedef Node* node;
node MakeNode(int x){
    node temp = new Node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}
int GetSize(node back){
    int ans = 0;
    while(back != NULL){
        ++ans;
        back = back->next;
    }
    return ans;
}
bool Epmty(node back){
    return back == NULL;
}
void Push(node &back, int x){
    node temp = MakeNode(x);
    temp->next = back;
    back = temp;
}
void Pop(node &front){
    if(front == NULL){
        cout << "Danh sach rong"; return;
    }else{
        node truoc = front, sau = NULL;
        while(truoc->next != NULL){
            sau = truoc;
            truoc = truoc->next;
        }
        if(sau == NULL){
            front = front->next;
            // front = NULL;
        }else{
            sau->next = truoc->next;
        }
    }
}
int GetFront(node front){
    while(front->next != NULL){
        front = front->next;
    }
    return front->data;
}
int main(){
    node back = NULL;
    Push(back, 6);
    Push(back, 8);
    vector<int> locphat;
    // sinh ra cac so loc phat co 9 chu so
    while(1){
        int top = GetFront(back); Pop(back);
        string res = to_string(top);
        if(res.length() == 9) break; 
        locphat.push_back(top);
        Push(back, top * 10 + 6);
        Push(back, top * 10 + 8);
    }
    for(int x : locphat) cout << x << " ";
    return 0;
}