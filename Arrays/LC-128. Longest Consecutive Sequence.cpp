#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int maxi = 1;
        int len = 1;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1] + 1){
                len++;
                maxi = max(maxi, len);
            }
            else if(nums[i] != nums[i-1]) len = 1;
        }
        return maxi;
    }
};