class Solution {
    public:
      int minCoins(vector<int> &coins, int sum) {
          sort(coins.rbegin(), coins.rend()); 
  
          int count = 0;
          for (int i = 0; i < coins.size(); i++) {
              if (coins[i] <= sum) {
                  int take = sum / coins[i];
                  count += take;
                  sum -= take * coins[i];
              }
          }
          if (sum != 0) return -1;
  
          return count;
      }
  };