
#include <iostream>
#include<vector>
using namespace std;

void merge(vector<int>&arr, int left, int mid, int right){
    vector<int> L(arr.begin()+left, arr.begin()+mid+1);
    vector<int> R(arr.begin()+mid+1, arr.begin()+right+1);
    
    int i = 0, j = 0, k = left;
    while(i < L.size() && j < R.size())
        arr[k++] = (L[i] <= R[j] ? L[i++] : R[j++]);
        
    while(i < L.size()) arr[k++] = L[i++];
    while(j < R.size()) arr[k++] = R[j++];
}

void mergeSort(vector<int>&arr, int left, int right){
    if(left>=right) return;
    int mid = left +(right-left)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}


int main() {
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    
    vector<int>arr(n);
    cout<<"Enter the numbers:  ";
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    
    mergeSort(arr,0,n-1);
    
    cout<<"Sorted Array is : ";
    for(int x: arr){
        cout<<x<<"   ";
    }

    return 0;
}