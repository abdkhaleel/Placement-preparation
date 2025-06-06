class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            int n = nums.size();
            int high = n - 1;
            int low = 0;
            while(low < high){
                int mid = low + (high - low) / 2; 
    
                if(mid&1) mid--;
    
                if(nums[mid] == nums[mid+1]) low = mid + 2;
    
                else high = mid;
            }
            return nums[low];
        }
    };