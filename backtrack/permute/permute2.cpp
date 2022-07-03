//
// Created by shanshan on 2022/5/11.
/*
 * 所给的序列中有重复的数字
 */
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ret;
vector<int> path;
void backtrack(vector<int>&nums,vector<bool>& used){
    if(path.size()==nums.size()){
        ret.push_back(path);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(i>0&&nums[i]==nums[i-1]&&used[i-1]==false){
            continue;
        }
        if(used[i]==false){
            used[i]=true;
            path.push_back(nums[i]);
            backtrack(nums,used);
            path.pop_back();
            used[i]=false;
        }
    }
}
vector<vector<int>> permute2(vector<int>& nums){
    ret.clear();
    path.clear();
    vector<bool> used(nums.size(),false);
    backtrack(nums,used);
    return ret;
}
int main(){
    vector<int> nums={1,1,2};
    vector<vector<int>> o=permute2(nums);
    for(int i=0;i<o.size();i++){
        for(int j=0;j<o[0].size();j++){
            cout<<o[i][j];
        }
        cout<<","<<endl;
    }
}