#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
Node* createTree(Node* root,int value){
    if(root==NULL){
        Node* node=new Node(value);
        root=node;
    }
    else if(value<root->data){
        root->left=createTree(root->left,value);
    }
    else
    root->right=createTree(root->right,value);
    return root;
}
bool Search(Node* root,int value){
    if(root==NULL)
    return false;
    else if(root->data==value)
    return true;
    else if(value<root->data){
        Search(root->left,value);
    }
    else
    Search(root->right,value);
}
void print(Node* root){}
int main(){
    Node* root=NULL;
    root=createTree(root,10);
    root=createTree(root,7);
    root=createTree(root,8);
    root=createTree(root,6);
    root=createTree(root,12);
    root=createTree(root,11);
    root=createTree(root,13);
    if(Search(root,12)){
        cout<<"Element found"<<endl;
    }
    else
    cout<<"Not found"<<endl;
    return 0;
}