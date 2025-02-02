#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = n * m - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            auto [row, col] = make_pair(mid/m, mid%m);
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};