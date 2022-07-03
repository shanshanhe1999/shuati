//
// Created by shanshan on 2022/5/8.
//
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
    vector<int> path;
    vector<vector<int>> ret;
    void backtrack(vector<int>& nums,int startIdx){
        if(path.size()>1){
            ret.push_back(path);
        }
        for(int i=startIdx;i<nums.size();i++){
            /*if(i>startIdx&&nums[i]<nums[i-1]){
                continue;
            }应该用path.back()与nums[i]比较而不是nums[i-1]
             */
            //加一个哈希映射，不重复使用相同元素
            unordered_set<int> used;
            if(!path.empty()&&nums[i]<path.back()||used.find(nums[i])!=used.end()){
                continue;
            }
            path.push_back(nums[i]);
            backtrack(nums,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums){
        ret.clear();path.clear();
        backtrack(nums,0);
        return ret;
    }
};