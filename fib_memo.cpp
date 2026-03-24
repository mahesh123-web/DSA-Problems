#include<iostream>
#include<vector>
using namespace std;

vector<long long> memo(100, -1);
long long fib(int n){
    if(n <= 1) return n;
    if(memo[n] != -1) return memo[n];
    
    memo[n] = fib(n-1) + fib(n-2);
    return memo[n];
}

int main(){
    cout<<fib(10)<<endl;
    cout<<fib(50)<<endl;
    
    return 0;
}