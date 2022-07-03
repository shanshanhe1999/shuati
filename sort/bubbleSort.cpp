//
// Created by shanshan on 2022/6/18.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    void swap(vector<int>& nums,int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    void bubbleSort(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size()-i-1;j++){
                if(nums[j]>nums[j+1]){
                    swap(nums,j,j+1);
                }
            }
        }
    }
    vector<int> sort(){
        vector<int> vec={1,3,7,2,5};
        bubbleSort(vec);
        for(int i : vec){
            cout<<i;
        }
        return vec;
    }
};
int main(){
    Solution s;
    s.sort();
    return 0;
}
