//
// Created by shanshan on 2022/5/5.
//
#include <vector>
#include <cstdlib>

using namespace std;

class quickSort{
public:
    static void swap(vector<int>& nums,int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    int partition(vector<int>& nums,int low,int high){
        //if(low==high) return low;
        swap(nums,low,low+rand()%(high-low+1));
        int begin=low;
        while(low<high){
            while(low<high&&nums[begin]<nums[high]){
                high--;
            }
            while(low<high&&nums[begin]>=nums[low]){
                low++;
            }
            swap(nums,low,high);
        }
        swap(nums,begin,high);
        return high;
    }
    void quicksort(vector<int>& nums,int low,int high){
        if(low>=high) return;
        int idx=partition(nums,low,high);
        quicksort(nums,low,idx-1);
        quicksort(nums,idx+1,high);
    }
    vector<int> sortArray(vector<int>& nums){
        //vector<int> ret;
        quicksort(nums,0,(int)nums.size()-1);
        return nums;
    }
};
//冒泡排序
class paosort{
public:
    vector<int> sortArray(vector<int>& nums){
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=1;j<n-i;j++){
                if(nums[j]<nums[j-1]){
                    int temp=nums[j];
                    nums[j]=nums[j-1];
                    nums[j-1]=temp;
                }
            }
        }
        return nums;
    }
};
//选择排序
class selectSort{
public:
    vector<int> sortArray(vector<int>& nums){
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            int min=i;
            for(int j=i+1;j<n;j++){
                if(nums[min]>nums[j]){
                    min=j;
                }
            }
            if(min!=i){
                swap(nums[i],nums[min]);
            }
        }
        return nums;
    }
};
//插入排序
class insertSort{
public:
    vector<int> sortArray(vector<int>& nums){
        int n=nums.size();
        for(int i=1;i<n;i++){
            int flag=nums[i];
            int j=i-1;
            while(j>=0&&flag<nums[j]){
                nums[j+1]=nums[j];
                j--;
            }
            nums[j+1]=flag;
        }
        return nums;
    }
};
//归并排序
class mergeSort{
public:
    void merge(vector<int>& nums,int left,int right,vector<int>& ret){
        int mid=(right-left)/2+left;
        int i=left,j=mid+1,k=0;
        while(i<mid&&j<=right){
            if(nums[i]<=nums[j])
                ret[k++]=nums[i++];
            else
                ret[k++]=nums[j++];
        }
        while(i<=mid){
            ret[k++]=nums[i++];
        }
        while(j<=right){
            ret[k++]=nums[j++];
        }
        for(int i=left;i<right;i++){
            nums[i]=ret[i-left];
        }
    }
    void mergesort(vector<int>& nums,int left,int right,vector<int>& ret){
        if(left>=right) return;
        int mid=(right-left)/2+left;
        mergesort(nums,left,mid,ret);
        mergesort(nums,mid+1,right,ret);
        merge(nums,left,right,ret);
    }
    vector<int> sortArray(vector<int>& nums){
        vector<int> ret(nums.size());
        mergesort(nums,0,nums.size()-1,ret);
        return nums;
    }
};