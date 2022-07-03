//
// Created by shanshan on 2022/5/11.
//
#include <iostream>
using namespace std;

int main(){
    string a,s;
    getline(cin,a);
    int mid=a.length()/2-1;int top=0;
    for(int i=0;i<=mid;i++){
        top++;
        s[top]=a[i];
    }
    int i=0;
    if(a.length()%2==0) i=mid+1;
    else i=mid+2;
    for(;i<a.length();i++){
        if(a[i]!=s[top]){
            break;
        }
        top--;
    }
    if(top==0){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}