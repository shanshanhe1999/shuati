//
// Created by shanshan on 2022/5/9.
//
#include <iostream>
//#include <string.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;string t;
    for(int i=0;i<n;i++){
        s+='*';
        t+=' ';
    }
    string ret;
    for(int i=0;i<n;i++){
        ret=t.substr(0,i)+s.substr(i,n-i);
        cout<<ret<<endl;
    }
    return 0;
}