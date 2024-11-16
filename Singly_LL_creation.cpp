//Constant time for interting node at end
#include<iostream>
using namespace std;
class Node{//class declaration
    public://access modifier
    int data;//data member to hold data in node
    Node *next;//next pointer variavble of Node type to hold address of another node
    Node(int data){//constructor to initialize the value if sigantura matches
        this->data=data;//constructor's initialized data value
        this->next=NULL;//constructor's initialized next value
    }
};
Node* insertNodeAtend(Node* temp,int data){//function to insert node at end with O(1)
    Node* node=new Node(data);
    //dynamic memory allocation of Node(with data) and variable node pointer of type Node stores data
    temp->next=node;//linking previous node's next pointer to the newly created node
    return node;//returning the node pointer 
}
void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL";
}
int main(){    //main function
    Node* head=new Node(170);//declaring head
    Node* temp=head;//another pointer variable temp of type Node to store head's value
    temp=insertNodeAtend(temp,2);//inserting at end
    temp=insertNodeAtend(temp,3);
    temp=insertNodeAtend(temp,1);
    temp=head;
    print(temp);
    return 0;
}