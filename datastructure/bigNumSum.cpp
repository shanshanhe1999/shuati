//
// Created by shanshan on 2022/5/10.
//
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

string bigSum(string& s1,string& s2){
    int l1=s1.length()-1;int l2=s2.length()-1;
    string ret="";
    int carry=0;
    while(l1!=0||l2!=0||carry!=0){
        int temp=s1[l1]-'0'+s2[l2]-'0'+carry;
        ret+=temp%10+'0';
        carry=temp/10;
        l1--;l2--;
    }
    return ret;
}
int main(){
    string s1="123";
    string s2="789";
    string sum=bigSum(s1,s2);
    cout<<s1<<" "<<s2<<endl;
    cout<<sum<<endl;
    //return 0;
}