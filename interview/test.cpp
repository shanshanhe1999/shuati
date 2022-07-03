//
// Created by shanshan on 2022/5/12.
//
#include <iostream>
using namespace std;

class Animal{
public:
    Animal(){}
    virtual void getType(){cout<<"dongwu"<<endl;}
};
class Tiger:public Animal{
public:
    Tiger(){}
    virtual void getType(){cout<<"tiger"<<endl;}
};
int a=10;
const int b=10;
static int c=10;

int main(){
    int d=10;
    const int e=10;
    static int f=10;
    Animal* an=new Tiger();
    an->getType();
    int* p1=new int;
    int* p2=new int[3];
    int* p3=(int*)malloc(sizeof(int)*3);
    delete p1;
    delete[] p2;
    free(p3);
    cout<<(void *)an<<endl;
    cout<<"全局变量:"<<&a<<endl;
    cout<<"全局常量:"<<&b<<endl;
    cout<<"静态全局变量:"<<&c<<endl;
    cout<<"局部变量:"<<&d<<endl;
    cout<<"局部常量:"<<&e<<endl;
    cout<<"静态局部变量:"<<&f<<endl;
    return 0;
}