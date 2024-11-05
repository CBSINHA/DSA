#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data=value;
        next=NULL;
    }
};
Node* InsertAtEnd(Node* &temp,int value){
    Node* node=new Node(value);
    temp->next=node;
    temp=temp->next;
    return temp;
}
void InsertAtPosition(Node* &head,int position,int value){
    Node* temp=head;
    int count=1;
    while(temp!=NULL){
        count++;
        if(count==position){
            Node* node=new Node(value);
            node->next=temp->next;
            temp->next=node;
        }
        temp=temp->next;
    }
}
void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    Node* head=new Node(10000);
    Node* temp=head;
    temp=InsertAtEnd(temp,1);
    temp=InsertAtEnd(temp,2);
    temp=InsertAtEnd(temp,5);
    temp=InsertAtEnd(temp,3);
    temp=head;
    display(temp);
    InsertAtPosition(head,4,4);
    display(head);
    return 0;
}