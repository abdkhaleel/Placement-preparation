class Solution {
    public:
      static bool cmp(pair<int, int> a, pair<int, int> b){
          double r1 = (double) a.first / (double) a.second;
          double r2 = (double) b.first / (double) b.second;
          return r1 > r2;
      }
      // Function to get the maximum total value in the knapsack.
      double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
          // Your code here
          vector<pair<int, int>> arr;
          for(int i = 0; i < wt.size(); i++) arr.push_back({val[i], wt[i]});
          sort(arr.begin(), arr.end(), cmp);
          int weight = 0;
          double ans = 0.0;
          for(auto& it: arr){
              if(weight + it.second <= capacity){
                  ans += it.first;
                  weight += it.second;
              }else{
                  int remain = capacity - weight;
                  double val = ((double) it.first / (double) it.second) * (double) remain;
                  ans += val;
                  break;
              }
          }
          return ans;
          
      }
  };