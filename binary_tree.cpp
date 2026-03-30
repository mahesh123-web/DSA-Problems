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

Node* search(Node* root, int val){
    if(!root || root->data == val) return root;
    if(val < root->data){
        return search(root->left, val);
    }else{
        return search(root->right, val);
    }
}

Node* minNode(Node* root){
    while(root->left){
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int val){
    if(!root) return nullptr;
    if(val < root->data){
        root->left = deleteNode(root->left, val);
    }
    else if(val > root->data){
        root->right = deleteNode(root->right, val);
    }
    else{
        //No child
        if(!root->left && !root->right){
            delete root;
            return nullptr;
        }
        //One child
        if(!root->left){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(!root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Two childrens(Replacing with inorder successor)
        Node* succ  = minNode(root->right);
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
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

    cout<<"Enter the element to be search: ";
    cin>>val;

    Node* result = search(root, val);
    if(result){
        cout<<"Element Found: "<<result->data<<endl;
    }else{
        cout<<"Element is not found"<<endl;
    }

    Node* min = minNode(root);
    cout<<"The Minimum Element is : "<<min->data<<endl;

    
    cout<<"Enter the Element to be delete: ";
    cin>>val;
    root = deleteNode(root,val);
    cout<<"\nInorder Traversal : "<<endl;
    inorder(root);

    return 0;
}