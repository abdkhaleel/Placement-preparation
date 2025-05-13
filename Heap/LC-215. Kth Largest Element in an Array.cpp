class Solution {
    public:
        
        int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int> pq;
            for(int& n: nums) pq.push(n);
            int c = 1;
            while(!pq.empty()){
                if(c == k) break;
                pq.pop();
                c++;
            }
            return pq.top();
        }
    };