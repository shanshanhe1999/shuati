//
// Created by shanshan on 2022/6/22.
//
#include <vector>
using namespace std;


void selectSort(vector<int>& nums){
    for(int i=0;i<nums.size();i++){
        int minIdx=i;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]<nums[minIdx]){
                minIdx=j;
            }
        }
        if(minIdx!=i){
            swap(nums[i],nums[minIdx]);
        }
    }
}
