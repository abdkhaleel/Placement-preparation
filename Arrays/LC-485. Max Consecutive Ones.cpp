class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int cmax = 0, tmax = 0;
            for(int& x: nums){
                if(x == 1) cmax++;
                else cmax = 0;
                tmax = max(cmax, tmax);
            }
            return tmax;
        }
    };