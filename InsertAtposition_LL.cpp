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
void InsertAtEnd(Node* &head,int value){
    Node* node=new Node(value);
    if(head==NULL){
        head=node;
        return;
    }

}
int main(){
    
    return 0;
}