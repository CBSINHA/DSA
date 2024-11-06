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
void deleteAtHead(Node* &head){
    Node* temp=head;
    head=head->next;
    delete temp;
}
void printList(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    Node* head=NULL;
    InsertAtHead(head,1);
    InsertAtHead(head,2);
    InsertAtHead(head,789);
    InsertAtHead(head,9608);
    InsertAtHead(head,1);
    printList(head);
    deleteAtHead(head);
    printList(head);
    deleteAtHead(head);
    deleteAtHead(head);
    printList(head);
    return 0;
}