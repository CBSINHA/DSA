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
void insertAtPosition(Node* &head,int value, int pos){
    Node* temp=head;
    int count=1;
    Node* node=new Node(value);
    if(temp==NULL){
        head=node;
    }
    while(temp!=NULL){
        if(count==pos){
            break;
        }
        count++;
        temp=temp->next;
    }
        temp->prev->next=node;
        node->prev=temp->prev;
        node->next=temp;
        temp->prev=node;
}
void deleteAtPosition(Node* &head,int pos){
    Node* temp=head;
    int count=1;
    while(temp!=NULL){
        if(count==pos){
            break;
        }
        count++;
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete temp;
    temp=NULL;
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
    cout<<endl;
    insertAtPosition(head,4000,2);
    display(head);
    cout<<endl;
    deleteAtPosition(head,2);
    display(head);
 return 0;
}