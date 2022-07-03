//
// Created by shanshan on 2022/5/7.
//
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;

class recoverip{
private:
    vector<vector<string>> ret;
    vector<string> ip;
public:
    void backtrack(const string& s,int startIdx,int pointNum){
        if(startIdx>=s.size()){
            ret.push_back(ip);
            return;
        }
        for(int i=startIdx;i<s.size();i++){
            if(isValid(s,startIdx,i)){
                s.insert(s.begin()+i+1,'.');
                
            }
        }
    }
    bool isValid(const string& s,int start,int end){
        if(start>end) return false;
        if(s[start]=='0'&&start!=end) return false;
        int num=0;
        for(int i=start;i<=end;i++){
            if(s[i]>'9'||s[i]<'0') return false;
            num=num*10+(s[i]-'0');
            if(num>255) return false;
        }
        return true;
    }
    vector<vector<string>> recover(const string& s){
        ret.clear();
        ip.clear();
        backtrack(s,0);
        return ret;
    }
};
int main(){
    recoverip ip;
    vector<vector<string>> output=ip.recover("101023");
    for(int i=0;i<output.size();i++){
        for(int j=0;j<output[0].size();j++){
            cout<<output[i][j];
        }
        cout<<"'"<<endl;
    }
}