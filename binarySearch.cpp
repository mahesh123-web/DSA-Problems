#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& arr, int target){
    int low = 0, high = arr.size()-1;
    
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the elment to search: ";
    cin>>target;
    
    int result = binarySearch(arr,target);
    
    if(result != -1){
        cout<<"Element found at index: "<<result;
    }else{
        cout<<"Element is not found";
    }
    return 0;
}