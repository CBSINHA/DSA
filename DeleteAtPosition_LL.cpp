#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* link;
    Node(int value){
        this->data=value;
        link=NULL;
    }
};
void addnodeAtEnd(Node* &head,int value){
    Node* n=new Node(value);
    if(head==NULL){
        head=n;
        return;
    }
    Node* temp=head;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=n;
}
void deleteNode(Node* &head,int value){
    Node* temp=head;
    Node* tmp=temp;
    if(head==NULL)
    return;
    if(head->data==value){
        head=head->link;
        delete temp;
        return;
    }
    while(temp->data!=value){
        tmp=temp;
        temp=temp->link;
        if(temp==NULL)
        return;
    }
    tmp->link=temp->link;
    delete temp;
}
void displayLL(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->link;
    }
    cout<<"NULL"<<endl;
}
int main(){
    Node* head=NULL;
    addnodeAtEnd(head,1);
    addnodeAtEnd(head,2);
    addnodeAtEnd(head,7);
    addnodeAtEnd(head,11);
    deleteNode(head,2);
    displayLL(head);
    return 0;
}