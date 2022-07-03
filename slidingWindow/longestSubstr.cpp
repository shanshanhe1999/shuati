//
// Created by shanshan on 2022/5/11.
//
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstr(const string& s){
    int ret=INT32_MIN;
    unordered_map<char,int> window;
    int left=0;int right=0;string substr="";
    while(right<s.length()){
        char r=s[right];
        window[r]++;
        while(window[r]>1){
            char l=s[left];
            left++;
            window[l]--;
        }
        if(ret<right-left+1){
            ret=right-left+1;
            string str=s.substr(left,right-left+1);
            substr=str.size()>substr.size()?str:substr;
            
        }
        ret=max(ret,right-left+1);
        right++;
    }
    cout<<"the longestSbustr is:"<<substr<<endl;
    return ret==INT32_MIN?0:ret;
}
int main(){
    string input;
    while(cin>>input){
        int output= lengthOfLongestSubstr(input);
        cout<<output<<endl;
    }
    return 0;
}