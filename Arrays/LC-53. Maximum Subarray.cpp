#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = -1e9;
        int sum = 0;
        for(int x: nums){
            sum += x;
            maxi = max(maxi, sum);
            sum = max(0, sum);
        }
        return maxi;
    }
};