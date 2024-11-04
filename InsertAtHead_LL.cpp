#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void InsertAtHead(Node* &head,int value){
    Node* node=new Node(value);
    if(head==NULL){
        head=node;
        return;
    }
    node->next=head;
    head=node;
}
void printList(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL";
}
int main(){
    Node* head=NULL;
    InsertAtHead(head,1);
    InsertAtHead(head,2);
    InsertAtHead(head,789);
    InsertAtHead(head,9608);
    InsertAtHead(head,1);
    printList(head);
    return 0;
}