class Solution {
private:
    string s1;
    string s2;
    int f(int i, int j, vector<vector<int>>& dp){
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return f(i-1, j-1, dp);
        int del = 1 + f(i, j-1, dp);
        int rep = 1 + f(i-1, j-1, dp);
        int ins = 1 + f(i-1, j, dp);

        return dp[i][j] = min({del, rep, ins});
    }
public:
    int minDistance(string word1, string word2) {
        // s1 =  word1;
        // s2 = word2;
        // vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        // return f(s1.size()-1, s2.size()-1, dp);
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 0; i <= m; i++) dp[0][i] = i;
        for(int i = 0; i <= n; i++) dp[i][0] = i;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    int del = 1 + dp[i][j-1];
                    int rep = 1 + dp[i-1][j-1];
                    int ins = 1 + dp[i-1][j];

                    dp[i][j] = min({del, rep, ins});
                }
            }
        }

        return dp[n][m];
    }
};