//
// Created by shanshan on 2022/4/23.
//
#include <vector>
#include <algorithm>

using namespace std;

class threeSum{
public:
    vector<vector<int>> threesum(vector<int>& nums,int target) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 3) return {};
        for (int first = 0; first < n; first++) {
            if (first > 0 && nums[first] == nums[first - 1])
                continue;
            target -= nums[first];
            int third=n-1;
            for(int second=first+1;second<n;second++){
                if(second>first+1&&nums[second]==nums[second-1])
                    continue;
                while(second<third&&nums[second]+nums[third]>target)
                    third--;
                if(second>=third) break;
                if(nums[second]+nums[third]==target)
                    ret.push_back({nums[first],nums[second],nums[third]});
            }
        }
        return ret;
    }
};