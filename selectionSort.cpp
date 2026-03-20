#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>&arr){
    int swapCount = 0;
    int n = arr.size();
    for(int i = 0;i < n-1; i++){
        int minIdx = i;
        for(int j = i+1; j < n; j++){
            if(arr[j]<arr[minIdx]){
                minIdx = j;
            }
        }
        if(minIdx != i){
            swap(arr[i],arr[minIdx]);
            swapCount++;
        }
    }
    cout<<"Swap count is: "<<swapCount <<endl;
    
}


int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    
    vector<int>arr(n);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionSort(arr);
    
    cout<<"Sorted array: ";
    for(int x: arr){
        cout<<x<<"   ";
    }
    return 0;
}