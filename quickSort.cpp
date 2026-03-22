#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

int partition(vector<int>&arr, int low, int high){
    int randIdx = low + rand() % (high - low + 1);
    swap(arr[randIdx],arr[high]);
    
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j< high; j++){
        if(arr[j]<= pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(vector<int>&arr, int low, int high){
    if(low >= high) return;
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
}

int main(){
    int n;
    cout<<"Enter the number of elements:  ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    srand(42);
    quickSort(arr, 0, arr.size()-1);
    
    
    cout<<"The sorted Elements are:  ";
    for(int x: arr){
        cout<<x<<"   ";
    }
    
    return 0;
}


