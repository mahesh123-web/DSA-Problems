#include<iostream>
#include<vector>
using namespace std;

// ============= Max Heap =====================

void heapifyUp_max(vector<int>&heap, int i){
    int parent = (i-1)/2;
    if(i > 0 && heap[i] > heap[parent]){
        swap(heap[i], heap[parent]);
        heapifyUp_max(heap, parent);
    } 
}

void heapifyDown_max(vector<int>&heap, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    int n = heap.size();

    if(left < n && heap[left] > heap[largest]){
        largest = left;
    }
    if(right < n && heap[right] > heap[largest]){
        largest = right;
    }

    if(largest != i){
        swap(heap[i],heap[largest]);
        heapifyDown_max(heap,largest);
    }
}

void insert_max(vector<int> &heap, int val){
    heap.push_back(val);
    heapifyUp_max(heap, heap.size()-1);
}

int delete_max(vector<int> &heap){
    int maxVal = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown_max(heap,0);
    return maxVal;
}

void display(vector<int> &heap){
    for(int x : heap){
        cout<<x<<"  ";
    }
    cout<<endl;
}


int main(){
    vector<int> maxHeap;
    int n, val;

    cout<<"Enter the number of elements: ";
    cin>>n;

    cout<<"Enter the values: ";
    for(int i=0;i<n;i++){
        cin>>val;
        insert_max(maxHeap, val);
    }

    cout<<"\nMax Heap: ";
    display(maxHeap);

    cout<<"\nElement Deleted from Max Heap: "<<delete_max(maxHeap)<<endl;
    cout<<"Max Heap After Deletion: ";display(maxHeap);

    return 0;
}