#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int, int> mp;
        // int n = nums.size();
        // for(int x: nums) mp[x]++;
        // for(auto& it: mp) if(it.second > n/2) return it.first;
        // return -1;
        int candidate, count = 0;
        for(int x: nums){
            if(count == 0) candidate = x;
            if(candidate == x) count++;
            else count--;
        }
        return candidate;
    }
};