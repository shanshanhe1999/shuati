//
// Created by shanshan on 2022/6/22.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    void swap(vector<int>& nums,int i,int j){
        int tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
    }
    
    void insertSort(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            int tmp=nums[i];
            int j=i-1;
            while(j>=0&&nums[j]>tmp){
                nums[j+1]=nums[j];
                j--;
            }
            nums[j+1]=tmp;
        }
    }
};

int main(){
    Solution so;
    vector<int> nums={2,4,1,3,5};
    for(int i:nums){
        cout<<i;
    }
    so.insertSort(nums);
    for(int i:nums){
        cout<<i;
    }
}