class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        string s;
        bool check = true;
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n-1; i++){
                if(strs[i][j] != strs[i+1][j]){
                    check = false;
                }
            }
            if(check) s.push_back(strs[0][j]);

            else break;

        }

        return s;
    }
};