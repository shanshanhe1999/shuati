//
// Created by shanshan on 2022/5/8.
//
/*
 * 排列问题关键在于顺序
 * 一个元素使用过的定义是：在特定的位置使用
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    vector<int> path;
    vector<vector<int>> ret;
    
    void backtrack(vector<int>& nums,vector<bool>& used){
        if(path.size()==nums.size()){
            ret.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            path.push_back(nums[i]);
            used[i]=true;
            backtrack(nums,used);
            used[i]=false;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums){
        vector<bool> used(nums.size(),false);
        backtrack(nums,used);
        return ret;
    }
};
int main(){
    Solution so;
    vector<int> nums={1,2,3};
    vector<vector<int>> output;
    output=so.permute(nums);
    for(int i=0;i<output.size();i++){
        for(int j=0;j<output[0].size();j++){
            std::cout<<output[i][j];
        }
        std::cout<<","<<endl;
    }
}