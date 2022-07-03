//
// Created by shanshan on 2022/5/7.
//
/*
 * 从1-9中相加之和为n的k个数的组合，
 * 每个解不能重复；
 * 每个解内部数字不能重复
 */
#include <vector>
#include <algorithm>
using namespace std;

class combinationsum{
private:
    vector<int> path;
    vector<vector<int>> ret;
    
public:
    void backtrack(vector<int>& candidates,int target,int sum,int startIdx){
        if(sum>target) return;
        if(sum==target){
            ret.push_back(path);
            return;
        }
        for(int i=startIdx;i<candidates.size();i++){
            //剪枝：sum>target的时候就可以结束循环了，因为后面的数越来越大
            sum+=candidates[i];
            path.push_back(candidates[i]);
            backtrack(candidates,target,sum,i);
            sum-=candidates[i];
            path.pop_back();
        }
        //40题
        for(int i=startIdx;i<candidates.size();i++){
            if(i>startIdx&&candidates[i]==candidates[i-1]) continue;
            //其余无修改
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates,int target){
        ret.clear();
        path.clear();
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0,0);
        return ret;
    }
};