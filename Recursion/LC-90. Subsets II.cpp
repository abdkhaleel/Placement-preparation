class Solution {
    public:
        void f(vector<int>& nums, vector<vector<int>>& ans, int ind, vector<int>& tmp){
            if(ind == nums.size()){
                ans.push_back(tmp);
                return;
            }
            tmp.push_back(nums[ind]);
            f(nums, ans, ind + 1, tmp);
            tmp.pop_back();
            
            while(ind + 1 < nums.size() && nums[ind] == nums[ind+1]) ind++;
            f(nums, ans, ind + 1, tmp);
        }
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> ds;
            sort(nums.begin(), nums.end());
            f(nums, ans, 0, ds);
            return ans;
        }
    };