#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<"   ";
    inorder(root->right);
}

void preorder(Node* root){
    if(!root) return;
    cout<<root->data<<"  ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(!root) return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"  ";
}

Node* insert(Node* root, int val){
    if(!root) return new Node(val);
    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else if(val > root->data){
        root->right = insert(root->right, val);
    }
    return root;
}


int main(){
    Node* root = nullptr;
    int n, val;

    cout<<"Enter the number of nodes: ";
    cin>>n;

    cout<<"Enter the values: ";
    for(int i=0;i<n;i++){
        cin>>val;
        root = insert(root,val);
    }

    cout<<"\nInorder Traversal : ";
    inorder(root);
    cout<<"\nPreorder Traversal : ";
    preorder(root);
    cout<<"\nPostorder Traversal : ";
    postorder(root);
    cout<<endl;

    return 0;
}