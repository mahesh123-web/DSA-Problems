// Finding the Middle Node Element in linked list

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* findmidNode(Node* head){
    Node* fast = head;
    Node* slow = head;
    
    if(!head) return nullptr;
    while(fast!=nullptr && head->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
};

Node* buildList(int arr[],int n){
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for(int i = 1; i<n; i++){
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
};

void printList(Node* head){
    while(head){
        cout<<head->data;
        if(head->next){
            cout<<"->";
        }
        head = head->next;
    }
    cout<<"-> NULL\n";
};

int main(){
    int a;
    cout<<"Enter the number elements in the array: "<<endl;
    cin>>a;
    int arr[a];
    cout<<"Enter the elemants: "<<endl;
    for(int i=0;i<a;i++){
        cin>>arr[i];
    }
    
    Node* head1 = buildList(arr,a);
    printList(head1);
    cout<<"Middle node is: "<<findmidNode(head1)->data<<"\n";
    
    return 0;
}