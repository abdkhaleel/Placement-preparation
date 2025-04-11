class Solution {
    public:
        vector<vector<string>> partition(string s) {
            vector<vector<string>> res;
            vector<string> part;
            function<void(int)> dfs = [&](int i){
                if(i >= s.size()){
                    res.push_back(part);
                    return;
                }
                for(int j = i; j < s.size(); j++){
                    if(isPali(s, i, j)){
                        part.push_back(s.substr(i, j - i + 1));
                        dfs(j + 1);
                        part.pop_back();
                    }
                }
            };
            dfs(0);
            return res;
        }
        bool isPali(string s, int i, int j){
            while(i < j){
                if(s[i] != s[j]) return false;
                i++; j--;
            }
            return true;
        }
    };