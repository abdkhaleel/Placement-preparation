class Solution {
  public:
    vector<int> val, wt;
    int f(int i, int W, vector<vector<int>>& dp){
        if(i == 0){
            if(wt[i] <= W) return val[0];
            return 0;
        }
        if(dp[i][W] != -1) return dp[i][W];
        int npick = f(i-1, W, dp);
        int pick = -1e9;
        if(wt[i] <= W) pick = val[i] + f(i-1, W-wt[i], dp);
        return dp[i][W] = max(pick, npick);
        
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        // int n = val.size();
        // this->val = val;
        // this->wt = wt;
        // vector<vector<int>> dp(n, vector<int>(W+1, -1));
        // return f(n-1, W, dp);
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        for(int i = 1; i <= W; i++) if(wt[0] <= i) dp[0][i] = val[0];
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= W; j++){
                int npick = dp[i-1][j];
                int pick = -1e9;
                if(wt[i] <= j) pick = val[i] + dp[i-1][j-wt[i]];
                dp[i][j] = max(pick, npick);
            }
        }
        return dp[n-1][W];
    }
};