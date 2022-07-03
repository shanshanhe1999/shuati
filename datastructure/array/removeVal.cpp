//
// Created by shanshan on 2022/5/19.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int removeElement(vector<int>& nums,int val) {
        int fast = 0;
        int slow = 0;
        while (fast < nums.size()) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};
int main(){
    vector<int> input={3,2,2,3};
    Solution so;
    int output=so.removeElement(input,3);
    cout<<output<<endl;
}