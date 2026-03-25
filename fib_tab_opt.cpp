#include<iostream>
#include<vector>
using namespace std;

int fibTab(int n){
    if (n <= 1) return n;
    vector<int>dp(n+1);
    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int fibOpt(int n){
    if(n<=1) return n;
    int prev2 = 0, prev1 = 1;
    for(int i = 2; i<=n; i++){
        int curr = prev1 + prev2;
        prev2= prev1;
        prev1 = curr;
    }
    return prev1;
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"The Fibonacci series : ";
    for(int i = 0; i < n; i++){
        cout<<fibTab(i)<<"   ";
    }
    cout<<endl;
    cout<<"The Fibonacci series : ";
    for(int i = 0; i < n; i++){
        cout<<fibOpt(i)<<"   ";
    }
    
    
    return 0;
}