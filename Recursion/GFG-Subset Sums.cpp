class Solution {
    public:
      void f(int ind, vector<int>& ans, vector<int>& arr, int sum){
          if(ind == arr.size()){
              ans.push_back(sum);
              return;
          }
          f(ind + 1, ans, arr, sum + arr[ind]);
          f(ind + 1, ans, arr, sum);
      }
      vector<int> subsetSums(vector<int>& arr) {
          // code here
          vector<int> ans;
          f(0, ans, arr, 0);
          return ans;
      }
  };