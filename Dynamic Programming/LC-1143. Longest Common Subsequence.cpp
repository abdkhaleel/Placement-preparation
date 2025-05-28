class Solution {
public:
    int f(int i, int j, string s1, string s2){
        if(i < 0 || j < 0) return 0;
        if(s1[i] == s2[j]) return 1 + f(i-1, j-1, s1, s2);
        return max(f(i-1, j, s1, s2), f(i, j-1, s1, s2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        // return f(text1.size()-1, text2.size()-1, text1, text2);
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};