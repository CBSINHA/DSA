#include<iostream>
using namespace std;
class Singly_Node{
    public:
    int data;
    Singly_Node* next;
    Singly_Node(int data){
        this->data=data;
        next=NULL;
    }
};
class Doubly_Node{
    public:
    int data;
    Doubly_Node* prev;
    Doubly_Node* next;
    Doubly_Node(int data){
        this->data=data;
        prev=next=NULL;
    }
};
void SinglyLLaddAtEnd(Singly_Node* &tail,int data){
    Singly_Node* node=new Singly_Node(data);
    if(tail==NULL){
        tail=node;
        tail->next=tail;
        return;
    }
    node->next=tail->next;
    tail->next=node;
    tail=node;
}
void SinglyLLdisplay(Singly_Node* tail){
    Singly_Node* temp=tail->next;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail->next);
}
void DoublyLLaddAtEnd(Doubly_Node* &tail,int value){
    Doubly_Node* node=new Doubly_Node(value);
    if(tail==NULL){
        tail=node;
        node->next=node;
        node->prev=node;
    }
    node->prev=tail;
    node->next=tail->next;
    tail->next->prev=node;
    tail->next=node;
    tail=node;
    
}
void DoublyLLdisplay(Doubly_Node* tail){
    Doubly_Node* temp=tail->next;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail->next);
}
void ReverseDoublyLLdisplay(Doubly_Node* tail){
    Doubly_Node* temp=tail;
    do{
        cout<<temp->data<<" ";
        temp=temp->prev;
    }while(temp!=tail);
}
int main(){
    Singly_Node* tail=NULL;
    SinglyLLaddAtEnd(tail,1);
    SinglyLLaddAtEnd(tail,100);
    SinglyLLdisplay(tail);

    cout<<endl<<endl;
    Doubly_Node* tail1=NULL;
    DoublyLLaddAtEnd(tail1,1000);
    DoublyLLaddAtEnd(tail1,8000);
    DoublyLLdisplay(tail1);
    cout<<endl;
    ReverseDoublyLLdisplay(tail1);
}