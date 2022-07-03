//
// Created by shanshan on 2022/5/12.
//
#include <iostream>
using namespace std;

//全局变量
int ga=10;
int gb=10;
//全局常量
const int cga=10;
const int cgb=10;

int main(){
    //局部变量
    int a=10;
    int b=10;
    //静态局部变量
    static int sa=10;
    static int sb=10;
    //局部常量
    const int ca=10;
    const int cb=10;
    //打印各自地址
    cout<<"全局变量地址ga："<<(void *)(&ga)<<endl;
    /*
    cout<<"全局变量地址gb："<<&gb<<endl;
    cout<<"全局常量地址cga："<<&cga<<endl;
    cout<<"全局变量地址cgb："<<&cgb<<endl;
    cout<<"局部变量地址a："<<&a<<endl;
    cout<<"局部变量地址b："<<&b<<endl;
    cout<<"局部静态变量地址sa："<<&sa<<endl;
    cout<<"局部静态变量地址sb："<<&sb<<endl;
    cout<<"局部常量地址ca："<<&ca<<endl;
    cout<<"局部常量地址cb："<<&cb<<endl;
    */
}
