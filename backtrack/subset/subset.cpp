//
// Created by shanshan on 2022/5/7.
//
#include <vector>
#include <string>
using namespace std;

class subset{
private:
    vector<vector<int>> ret;
    vector<int> path;
public:
    void backtrack(vector<int>& nums,int startIdx){
        ret.push_back(path); // 收集子集，要放在终止添加的上面，否则会漏掉自己
        if(startIdx>=nums.size()){
            //ret.push_back(path);
            return;
        }
        for(int i=startIdx;i<nums.size();i++){
            path.push_back(nums[i]);
            backtrack(nums,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subSet(vector<int>& nums){
        ret.clear();
        path.clear();
        backtrack(nums,0);
        return ret;
    }
};