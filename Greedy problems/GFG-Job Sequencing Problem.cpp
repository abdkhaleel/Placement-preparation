
class Solution {
    public:
      static bool cmp(pair<int, int> a, pair<int, int> b){
          return a.second > b.second;
      }
      vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
          // code here
          vector<pair<int, int>> arr;
          for(int i = 0; i < deadline.size(); i++) arr.push_back({deadline[i], profit[i]});
          sort(arr.begin(), arr.end(), cmp);
          int maxi = 0;
          for(auto& it: arr) maxi = max(maxi, it.first);
          vector<int> slot(maxi+1, -1);
          int count = 0, total = 0;
          for(int i = 0; i < arr.size(); i++){
              int d = arr[i].first;
              int p = arr[i].second;
              for(int j = d; j >= 1; j--){
                  if(slot[j] == -1){
                      slot[j] = i;
                      total += p;
                      count++;
                      break;
                  }
              }
          }
          return {count, total};
      }
  };