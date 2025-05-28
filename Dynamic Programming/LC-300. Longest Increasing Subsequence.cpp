class Solution {
public:
    int f(int i, int prev, vector<int>& arr){
        if(i == arr.size()) return 0;
        int take = -1e9;
        int ntake = f(i+1, prev, arr);
        if(prev == -1 || arr[prev] < arr[i]) take = 1 + f(i+1, i, arr);
        return max(take, ntake);
    }
    int lengthOfLIS(vector<int>& nums) {
        // return f(0, -1, nums);,
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int ind = n-1; ind >= 0; ind--){
            for(int prev = n-1; prev >= -1; prev--){
                int npic = dp[ind+1][prev+1];
                int pic = 0;
                if(prev == -1 || nums[ind] > nums[prev]){
                    pic = 1 + dp[ind+1][ind+1];
                }
                dp[ind][prev+1] = max(pic, npic);
            }
        }
        return dp[0][0];
    }
};