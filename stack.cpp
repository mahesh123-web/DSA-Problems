
#include <iostream>
#include<stack>
#include<string>
using namespace std;

class MyStack{
    int arr[1000];
    int topIdx = -1;
    
    public:
    
    void push(int val){
        arr[++topIdx] = val;
    }
    
    void pop(){
        if(topIdx>=0){
            topIdx--;
        }
    }
    
    int top(){
        return arr[topIdx];
    }
    
    bool empty(){
        return topIdx == -1;
    }
    
    int size(){
        return topIdx+1;
    }
    
    void printStack(){
        if(topIdx == -1){
            cout<<"The stack is empty\n";
        }
        for(int i = topIdx; i>=0; i--){
            cout<<arr[i]<<endl;
        }
        cout<<endl;
    }
};

bool isBalanced(string s){
    stack<char>st;
    for(char c : s){
        if(c == '(' || c == '[' || c == '{'){
            st.push(c);
        }
        else{
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if(c == ')' && top != '(') return false;
            if(c == ']' && top != '[') return false;
            if(c == '}' && top != '{') return false;
        }
    }
    return st.empty();
}

int main() {
  
    MyStack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.printStack();
    
    string str;
    cout<<"Enter the string of brackets: ";
    cin>>str;
    
    if(isBalanced(str)){
        cout<<"Balanced";
    }
    else{
        cout<<"Unbalanced";
    }
    
    return 0;
}