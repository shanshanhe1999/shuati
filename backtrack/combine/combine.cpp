//
// Created by shanshan on 2022/5/11.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> path;
vector<vector<int>> ret;

void backtrack(int n,int k,int startIdx){
     if(path.size()==k){
         ret.push_back(path);
         return;
     }
     for(int i=startIdx;i<=n;i++){
         path.push_back(i);
         backtrack(n,k,i+1);
         path.pop_back();
     }
 }
 vector<vector<int>> combine(int n,int k){
    ret.clear();
    path.clear();
    if(k>n) return ret;
    backtrack(n,k,1);
    return ret;
}
 int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> output=combine(n,k);
    for(int i=0;i<output.size();i++){
        for(int j=0;j<output[0].size();j++){
            cout<<output[i][j]<<" ";
        }
        cout<<","<<endl;
    }
    return 0;
}
/*
 * 优化：
 *      当startIdx后面的元素不够时，就可以终止循环了
 *      for(int i=startIdx;i<=n-(k-path.size())+1;i++)
 */