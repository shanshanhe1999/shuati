//
// Created by shanshan on 2022/5/11.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> path;
vector<vector<int>> ret;

void backtrack(vector<int>& candidates,int sum,int targetSum,int startIdx,vector<bool>& used){
    //if(sum>targetSum) return;
    if(sum==targetSum){
        ret.push_back(path);
        return;
    }
    
    for(int i=startIdx;i<candidates.size()&&sum+candidates[i]<targetSum;i++){
        if(i>0&&candidates[i]==candidates[i-1]&&used[i-1]==true) continue;
        sum+=candidates[i];
        path.push_back(candidates[i]);
        used[i]=true;
        backtrack(candidates,sum,targetSum,i+1,used);
        used[i]=false;
        sum-=candidates[i];
        path.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates,int target){
    vector<bool> used(candidates.size(),false);
    path.clear();
    ret.clear();
    sort(candidates.begin(),candidates.end());
    backtrack(candidates,0,target,0,used);
    return ret;
}
int main(){
    vector<int> input;
    int size=0;cin>>size;
    int temp=0;
    for(int i=0;i<size;i++){
        cin>>temp;
        input[i]=temp;
    }
    vector<vector<int>> output;
    output= combinationSum2(input,5);
    for(int i=0;i<output.size();i++){
        for(int j=0;j<output[0].size();j++){
            cout<<output[i][j]<<endl;
        }
    }
}