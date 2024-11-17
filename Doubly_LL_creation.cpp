#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *prev,*next;
    Node(int value){
        data=value;
        prev=next=NULL;
    }
};
void insertAtEnd(Node* &head,int value){
    Node* n=new Node(value);
    if(head==NULL){
        head=n;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
}
void displayUsingprev(Node* head){
    while(head->next!=NULL){
        head=head->next;
    }
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->prev;
    }
}
void insertAthead(Node* &head,int value){
    Node* node=new Node(value);
    if(head==NULL){
    head=node; return ;}
    node->next=head;
    head->prev=node;
    head=node;
}
int main()
{
    Node* head=NULL;
    insertAtEnd(head,100);
    insertAtEnd(head,200);
    insertAtEnd(head,300);
    insertAtEnd(head,900);
    insertAthead(head,1);
    display(head);
    cout<<endl;
    displayUsingprev(head);
 return 0;
}