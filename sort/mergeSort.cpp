//
// Created by shanshan on 2022/6/22.
//
#include<vector>
using namespace std;

void merge(vector<int>& nums,int low,int mid,int high){
    int i=low;int j=mid+1;
    while(i<=mid&&j<=high){
        if(nums[i]<nums[high]){
            i++;
        }else{
        
        }
    }
}

void mergeSort(vector<int>& nums,int low,int high){
    if(low>=high){
        return;
    }
    int mid=low+(high-low)/2;
    mergeSort(nums,low,mid);
    mergeSort(nums,mid+1,high);
    merge(nums,low,mid,high);
}