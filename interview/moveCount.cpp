//
// Created by shanshan on 2022/5/9.
//
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int movingCount(vector<int>& nums){
    int ret;int count=0;
    unordered_map<int,int> window;
    //一次遍历计算1的个数
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            count++;
        }
    }
    //二次遍历滑动窗口记录需要移动的1的个数
    int right=0;int left=0;int n=0;
    while(right<nums.size()){
        int r=nums[right];
        if(r==1) n++;
        while(right-left+1>4){
            int l=nums[left];
            left++;
            if(l==1) n--;
        }
        ret=min(count-n,ret);
    }
    return ret;
}
int main(){
    vector<int> input={1,1,0,0,1,0,1,0,0};
    int ret= movingCount(input);
    cout<<ret<<endl;
    return 0;
}