class Solution {
    public:
        void f(int ind, int sum, int target, vector<int>& candidates, vector<vector<int>>& ans,
                vector<int>& ds){
            
            if(ind == candidates.size()){
                if(target == sum) ans.push_back(ds);
                return;
            }
            if(sum + candidates[ind] <= target){
                ds.push_back(candidates[ind]);
                f(ind, sum + candidates[ind], target, candidates, ans, ds);
                ds.pop_back();
            }
            f(ind + 1, sum, target, candidates, ans, ds);
        }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int> ds;
            f(0, 0, target, candidates, ans, ds);
            return ans;
        }
    };