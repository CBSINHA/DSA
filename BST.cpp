#include<iostream>
#include<queue>
#include<limits.h>
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
        return Search(root->left,value);
    }
    else
    return Search(root->right,value);
}
Node* findMin(Node* root){
    if(root==NULL){
        return NULL;    
    }
    else{
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
    }
}
Node* findMax(Node* root){
    if(root==NULL)
    cout<<"Empty BST"<<endl;
    else{
        while(root->right!=NULL){
            root=root->right;
        }
        return root;
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
bool IsBST(Node* root,long min,long max){
    if(root==NULL)return true;
    if(root->data<max&&root->data>min&&IsBST(root->left,min,root->data)&&IsBST(root->right,root->data,max)) return true;
    else return false;
}
Node* Delete(Node* root,int value){
    if(root==NULL) return root;
    else if(value<root->data){
        root->left=Delete(root->left,value);
    }
    else if(value>root->data) root->right=Delete(root->right,value);
    else{
        //case 1 no child
        if(root->left==NULL&&root->right==NULL){
            delete root;
            root=NULL;
        }
        else if(root->left==NULL){//root has only right child
            Node* temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL){//root has only left child
            Node* temp=root;
            root=root->left;
            delete temp;
        }
        else{//root has both left and right child
            Node* temp=findMin(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }
    return root;
}
Node* Find(Node* root,int value){
    if(root==NULL)return root;
    if(value<root->data) return Find(root->left,value);
    else if(value>root->data) return Find(root->right,value);
    else return root;
}
Node* InorderPredecessor(Node* root,int value){
    if(root==NULL) return root;
    Node* current=Find(root,value);
    if(current==NULL) return NULL;
    if(current->left!=NULL){
        return findMax(current-> left);
    }
    else{
        Node* ancestor=root;
        Node* predecessor=NULL;
        while(ancestor!=current){
            if(current->data>ancestor->data){
                predecessor=ancestor;
                ancestor=ancestor->right;
            }
            else ancestor=ancestor->left;
        }
        return predecessor;
    }
}
Node* InorderSuccessor(Node* root,int value){
    if(root==NULL)return root;
    Node* current=Find(root,value);
    if(current==NULL)return NULL;
    if(current->right!=NULL){
        return findMin(current->right);
    }
    else{
        Node* successor=NULL;
        Node* ancestor=root;
        while(ancestor!=current){
            if(current->data<ancestor->data){
                successor=ancestor;
                ancestor=ancestor->left;
            }
            else ancestor=ancestor->right;
        }
        return successor;
    }
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
    Node* min=findMin(root);
    cout<<"Min value: "<<min->data<<endl;
    Node* max=findMax(root);
    cout<<"Max Value: "<<max->data<<endl;
    cout<<"Height of tree: "<<heightTree(root)<<endl;
    cout<<"Level Order traversal: ";
    LevelOrderTraversal(root);
    cout<<"\nInOrder Traversal: ";
    InorderTraversal(root);
    cout<<"\nPreorder Traversal: ";
    PreOrderTraversal(root);
    cout<<"\nPostOrder Traversal: ";
    PostOrderTraversal(root);
    cout<<"\nIs This a binary tree?:";
    cout<<IsBST(root,LONG_MIN,LONG_MAX);
    //root=Delete(root,10);
    cout<<"\nAfter deletion: ";
    InorderTraversal(root);
    cout<<"\nInorder predecessor: ";
    Node* predecessor=InorderPredecessor(root,10);
    cout<<predecessor->data<<endl;
    cout<<"Inorder successor: ";
    Node* successor=InorderSuccessor(root,9);
    cout<<successor->data<<endl;
    return 0;
}