class Solution {
    public:
        void backtrack(string s, vector<string>& res, unordered_set<string>& dict,
                        string path, int start){
    
            if(start == s.length()){
                res.push_back(path.substr(0, path.length()-1));
                return;
            }
            for(int end = start+1; end <= s.length(); end++){
                string word = s.substr(start, end-start);
                if(dict.find(word) != dict.end()){
                    backtrack(s, res, dict, path + word + " ", end);
                }
            }
        }
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> dict(wordDict.begin(), wordDict.end());
            vector<string> res;
            string path = "";
            backtrack(s, res, dict, path, 0);
            return res;
        }
    };