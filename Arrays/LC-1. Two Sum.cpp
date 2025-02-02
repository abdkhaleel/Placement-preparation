#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> mp;
       for(int i = 0; i < nums.size(); i++){
        int balance = target - nums[i];
        if(mp.find(balance) != mp.end()) return {mp[balance], i};
        mp[nums[i]] = i;
       }
       return {-1, -1};
    }
};