#include<iostream>
#include<queue>
using namespace std;

class MyQueue{
    int arr[1000];
    int frontIdx = 0, backIdx = 0, sz = 0;
    public:
    void push(int val){
        arr[backIdx++ % 1000] = val;
        sz++;
    }
    
    void pop(){
        if(sz>0){
            frontIdx++;
            sz--;
        }
    }
    int front(){
        return arr[frontIdx % 1000];
    }
    
    bool empty(){
        return sz == 0;
    }
    int size(){
        return sz;
    }
    
    void print(){
        if(sz == 0){
            cout<<"The queue is empty.";
        }
        for(int i = 0; i < sz; i++){
            cout<<arr[(frontIdx+i)%1000]<<"   ";
        }
        cout<<endl;
    }
};

int main(){
    
    MyQueue mq;
    mq.push(10);
    mq.push(20);
    mq.push(30);
    mq.push(40);
    
    cout<<mq.front()<<endl;
    cout<<mq.size()<<endl;
    mq.print();
    
    return 0;
}