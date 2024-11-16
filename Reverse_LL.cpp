#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    Node(int data){
        value=data;
        next=NULL;
    }
};

void reverse(Node* &head){//trying to use 2 pointers to do it
    Node* prev=NULL;
    while(head!=NULL){
        Node* current=head;
        head=head->next;
        current->next=prev;
        prev=current;
    }
    head=prev;
}

void display(Node* head){
    while(head!=NULL){
        cout<<head->value<<" ";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

Node* create(Node* temp,int val){//adds Nodes to end
    Node* node=new Node(val);
    if(temp==NULL){
        return node;
    }
    temp->next=node;
    return node;
}

int main(){
    Node* head=NULL;
    head=create(head,10);
    Node* temp=head;
    temp=create(temp,20);
    temp=create(temp,30);
    temp=create(temp,70);
    temp=create(temp,100);
    cout<<"Normal LL"<<endl;
    display(head);
    cout<<"After reverse"<<endl;
    reverse(head);
    display(head);
    return 0;
}