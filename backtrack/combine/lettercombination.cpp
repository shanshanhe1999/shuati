//
// Created by shanshan on 2022/5/11.
//
#include <iostream>
#include <vector>
using namespace std;

vector<string> ret;
string path;
vector<string> letterMap={
        " ",
        "!@#",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
};
void backtrack(const string& s,int idx){
    if(path.size()==s.size()){
        ret.push_back(path);
        return;
    }
    int digit=s[idx]-'0';
    string temp=letterMap[digit];
    for(int i=0;i<temp.size();i++){
        path.push_back(temp[i]);
        backtrack(s,idx+1);
        path.pop_back();
    }
}
vector<string> letterCombination(const string& s){
    ret.clear();
    path.clear();
    backtrack(s,0);
    return ret;
}
int main(){
    string input;
    cin>>input;
    vector<string> output= letterCombination(input);
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<endl;
    }
    return 0;
}