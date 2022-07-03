//
// Created by shanshan on 2022/5/7.
//
#include <vector>
#include <string>
using namespace std;
class partitionstr{
private:
    vector<string>path;
    vector<vector<string>> ret;
public:
    void backtrack(const string& s,int startIdx){
        if(startIdx>=s.size()){
            ret.push_back(path);
            return;
        }
        for(int i=startIdx;i<s.size();i++){
            if(isPalindrome(s,startIdx,i)){
                string str=s.substr(startIdx,i-startIdx+1);
                path.push_back(str);
            }else{
                continue;
            }
            backtrack(s,i+1);
            path.pop_back();
        }
    }
    bool isPalindrome(const string& s,int start,int end){
        for(int i=start,j=end;i<j;i++,j++){
            if(s[i]!=s[j]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(const string& s){
        ret.clear();
        path.clear();
        backtrack(s,0);
        return ret;
    }
};