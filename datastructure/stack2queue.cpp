//
// Created by shanshan on 2022/5/10.
//
#include <stack>
using namespace std;

class myQueue{
public:
    stack<int> stIn;
    stack<int> stOut;
    
    myQueue();
    void push(int value){
        stIn.push(value);
    }
    int pop(){
        int ret;
        if(!stOut.empty()){
            ret=stOut.top();
            stOut.pop();
        }else{
            while(!stIn.empty()){
                int temp=stIn.top();stIn.pop();
                stOut.push(temp);
            }
        }
    }
    int peek(){
        int ret=this->pop();
        stOut.push(ret);
        return ret;
    }
    bool empty(){
        return stIn.empty()&&stOut.empty();
    }
};
int main(){
    myQueue mq;
    bool isEmpty=mq.empty();
    mq.push(1);
    mq.push(3);
    mq.peek();
    mq.pop();
}