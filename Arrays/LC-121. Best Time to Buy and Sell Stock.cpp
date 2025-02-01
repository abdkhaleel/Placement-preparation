#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int maxProfit = -1e9;
        for(int x: prices){
            buy = min(buy, x);
            int profit = x - buy;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};