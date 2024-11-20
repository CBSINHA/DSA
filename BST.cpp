#include<iostream>
#include<queue>
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
void findMin(Node* root){
    if(root==NULL){
        cout<<"Empty BST"<<endl;    
    }
    // else if(root->left==NULL){
    //     cout<<"Least value: "<<root->data<<endl;
    // }
    else{
    while(root->left!=NULL){
        root=root->left;
    }
    cout<<"Least value in BST= "<<root->data<<endl;
    }
}
void findMax(Node* root){
    if(root==NULL)
    cout<<"Empty BST"<<endl;
    else{
        while(root->right!=NULL){
            root=root->right;
        }
        cout<<"The maximum value in Bst= "<<root->data<<endl;
    }
}
int heightTree(Node* root){
    if(root==NULL)
    return -1;
    else{
        return max(heightTree(root->left)+1,heightTree(root->right)+1);
    }
}
void LevelOrderTraversal(Node* root){
    if(root==NULL)
    return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* current=q.front();
        cout<<current->data<<" ";
        if(current->left)
        q.push(current->left);
        if(current->right)
        q.push(current->right);
        q.pop();
    }
}
void InorderTraversal(Node* root){
    if(root==NULL) return;
    InorderTraversal(root->left);
    cout<<root->data<<" ";
    InorderTraversal(root->right);
}
void PreOrderTraversal(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}
void PostOrderTraversal(Node* root){
    if(root==NULL)return;
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node* root=NULL;
    root=createTree(root,10);
    root=createTree(root,7);
    root=createTree(root,8);
    root=createTree(root,6);
    root=createTree(root,12);
    root=createTree(root,11);
    root=createTree(root,13);
    root=createTree(root,9);
    if(Search(root,12)){
        cout<<"Element found"<<endl;
    }
    else
    cout<<"Not found"<<endl;
    findMin(root);
    findMax(root);
    cout<<"Height of tree: "<<heightTree(root)<<endl;
    cout<<"Level Order traversal: ";
    LevelOrderTraversal(root);
    cout<<"\nInOrder Traversal: ";
    InorderTraversal(root);
    cout<<"\nPreorder Traversal: ";
    PreOrderTraversal(root);
    cout<<"\nPostOrder Traversal: ";
    PostOrderTraversal(root);
    return 0;
}